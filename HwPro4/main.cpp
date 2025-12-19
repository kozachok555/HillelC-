#include <iostream>
#include <string>
#include <memory>
#include <queue>
#include <utility>

using namespace std;

class Document
{
	string m_content;

public:
	Document() = default;
	explicit Document(std::string text) : m_content(std::move(text)) {}
	void insert(size_t pos, const string &str)
	{
		if (m_content.empty())
		{
			m_content = str;
			return;
		}
		if (pos > m_content.length())
		{
			pos = m_content.length();
		}
		m_content.insert(pos, str);
	};
	void erase(size_t pos, size_t count)
	{
		if (m_content.empty())
		{
			return;
		}
		if (pos + count > m_content.size())
		{
			cout << "cant erase because of wrong size";
			return;
		}
		m_content.erase(pos, count);
	};
	void replace(size_t pos, size_t count, const string &str)
	{
		if (m_content.empty())
		{
			return;
		}
		if (pos + count > m_content.size())
		{
			cout << "cant replace because of wrong size";
			return;
		};
		m_content.replace(pos, count, str);
	};

	const string &getText() const
	{
		return this->m_content;
	}
};
class Command
{
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
};
class InsertTextCommand : public Command
{
	weak_ptr<Document> m_doc;
	string m_text;
	size_t m_pos;

public:
	InsertTextCommand(shared_ptr<Document> doc, string text, size_t pos);
	void execute() override
	{
		shared_ptr<Document> doc = m_doc.lock();
		if (!doc)
		{
			cout << "Document no longer exists. Skipping.\n";
			return;
		}
		doc->insert(m_pos, m_text);
	}
};
class EraseTextCommand : public Command
{
	weak_ptr<Document> m_doc;
	size_t m_pos;
	size_t m_count;

public:
	EraseTextCommand(shared_ptr<Document> doc, size_t pos, size_t count);
	void execute() override
	{
		shared_ptr<Document> doc = m_doc.lock();
		if (!doc)
		{
			cout << "Document no longer exists. Skipping.\n";
			return;
		}
		doc->erase(m_pos, m_count);
	}
};
class ReplaceTextCommand : public Command
{
	weak_ptr<Document> m_doc;
	string m_text;
	size_t m_pos;
	size_t m_count;

public:
	ReplaceTextCommand(shared_ptr<Document> doc, size_t pos, size_t count, string text);
	void execute() override
	{
		shared_ptr<Document> doc = m_doc.lock();
		if (!doc)
		{
			cout << "Document no longer exists. Skipping.\n";
			return;
		}
		doc->replace(m_pos, m_count, m_text);
	}
};
class CommandScheduler
{
	queue<unique_ptr<Command>> m_pending;

public:
	void schedule(unique_ptr<Command> cmd)
	{
		m_pending.push(std::move(cmd));
	}
	void runAll()
	{
		while (!m_pending.empty())
		{
			unique_ptr<Command> cmd = std::move(m_pending.front());
			m_pending.pop();
			if (cmd)
			{
				cmd->execute();
			}
		}
	}
};
InsertTextCommand::InsertTextCommand(shared_ptr<Document> doc, string text, size_t pos)
	: m_doc(doc), m_text(std::move(text)), m_pos(pos) {}

EraseTextCommand::EraseTextCommand(shared_ptr<Document> doc, size_t pos, size_t count)
	: m_doc(doc), m_pos(pos), m_count(count) {}

ReplaceTextCommand::ReplaceTextCommand(shared_ptr<Document> doc, size_t pos, size_t count, string text)
	: m_doc(doc), m_text(std::move(text)), m_pos(pos), m_count(count) {}

int main()
{
	auto doc1 = make_shared<Document>("Hello");
	auto doc2 = make_shared<Document>("World");

	CommandScheduler scheduler;

	cout << "Initial state:\n";
	cout << "doc1: \"" << doc1->getText() << "\"\n";
	cout << "doc2: \"" << doc2->getText() << "\"\n\n";

	scheduler.schedule(make_unique<InsertTextCommand>(doc1, " world", doc1->getText().size()));
	scheduler.schedule(make_unique<InsertTextCommand>(doc2, " framework", doc2->getText().size()));
	scheduler.schedule(make_unique<ReplaceTextCommand>(doc1, 6, 5, "C++"));

	{
		auto tempDoc = make_shared<Document>("Temporary document");
		scheduler.schedule(make_unique<ReplaceTextCommand>(tempDoc, 0, 9, "ShouldNotAppear"));
	}

	cout << "Running all commands...\n\n";
	scheduler.runAll();

	cout << "Final state:\n";
	cout << "doc1: \"" << doc1->getText() << "\"\n";
	cout << "doc2: \"" << doc2->getText() << "\"\n";

	return 0;
}
