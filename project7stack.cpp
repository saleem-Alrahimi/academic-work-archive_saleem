#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string word;
    Node *next;
};

class SimpleStack
{

public:
    Node *top;
    SimpleStack()
    {
        top = NULL;
    }

    // function to add word
    void push(const string &word)
    {
        Node *newnode = new Node();
        newnode->word = word;
        newnode->next = top;
        top = newnode;
    }

    // function to delete word (from the top)
    void pop()
    {
        if (top != NULL)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
            cout<<"Done .\n";
        }
        else
        {
            cout << "There Are No Words To Delete .\n";
        }
    }

    // function to print the words
    void printWords() const
    {
		if(top != NULL)
		{
	        Node *temp = top;
	        cout << "The Word In The Stack:\n";
	        while (temp != NULL)
	        {
	            cout << temp->word << " ";
	            temp = temp->next;
	        }
	        cout << endl;
		}
		else
		{
			cout<<"the stack is empty . \n";
		}
    }

    // function for looking for how often to repeat a word
    void wordcounter(const string &word) const
    {
        Node *temp = top;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->word == word)
            {
                count++;
            }
            temp = temp->next;
        }
        cout << "the word '" << word << "' has been repeated " << count << "times .\n";
        
    }

    // function to update a word
    void updateWord(const string &oldWord, const string &newWord)
    {
        Node *temp = top;
        bool isfound = false;
        while (temp != NULL)
        {
            if (temp->word == oldWord)
            {
                temp->word = newWord;
                isfound = true;
            }
            temp = temp->next;
        }
        if (isfound)
        {
            cout << "the update is done. \n";
        }
        else
        {
            cout << "the word is not found. \n";
        }
    }

    // destruction function
    ~SimpleStack()
    {
        while (top != NULL)
        {
            pop();
        }
    }
};

int main()
{
    SimpleStack diary;
    int choice;
    string word, newWord;

    do
    {
        cout << "1. Add Word\n2. Delete Word\n3. Print The Word\n4. Update Word\n5. Looking For Repeat Of a Word\n6. Exit\nEnter The Option Number: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter The Word : ";
            cin >> word;
            diary.push(word);
            break;
        case 2:
            diary.pop();
            break;
        case 3:
            diary.printWords();
            break;
        case 4:
            cout << "Enter The Old Word: ";
            cin >> word;
            cout << "Enter The New Word: ";
            cin >> newWord;
            diary.updateWord(word, newWord);
            break;
        case 5:
            cout << "Enter Word To Check : ";
            cin >> word;
            diary.wordcounter(word);
            break;
        case 6:
            cout << "Exit.\n";
            break;
        default:
            cout << "Incorrect Option .\n";
            break;
        }
    } while (choice != 6);

    return 0;
}
