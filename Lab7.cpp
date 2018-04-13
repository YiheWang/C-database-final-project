//============================================================================
// Name        : Lab7.cpp
// Author      : Yihe Wang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Message{
	protected:
		string rawMessage;
	public:
		Message();
		Message(string);
		virtual ~Message();
		virtual void printMessage();//dynamic binding with keyword virtual
};

Message::Message()
{
	//an empty constructor, no thing can be initialized
	//cout<<"You do not enter message, please enter a message: "<<endl;
	//getline(cin,rawMessage);
}

Message::Message(string message)
{
	rawMessage = message;
}

Message::~Message()
{
	//an empty destructor, no memory need to free
	//cout<<"Goodbye, Message"<<endl;
}

void Message::printMessage()
{
	cout<<"The message is: "<<rawMessage<<endl;
}

class MorseCodeMessage : public Message{
	private:
		vector<string> morseCodeMessage;
		void codeTranslator();
	public:
		MorseCodeMessage();
		MorseCodeMessage(string);
		~MorseCodeMessage();
		void printMessage();
};

MorseCodeMessage::MorseCodeMessage() : Message()
{
	codeTranslator();//translate the message
}

MorseCodeMessage::MorseCodeMessage(string message) : Message(message)
{
	codeTranslator();//translate the message
}

MorseCodeMessage::~MorseCodeMessage()
{
	morseCodeMessage.clear();
	//cout<<"GoodBye, MorseCodeMessage"<<endl;
}

void MorseCodeMessage::codeTranslator()
{
	for(auto i:rawMessage){
		switch(i){
			case 'A':
			case 'a':
				morseCodeMessage.push_back(".-");
				break;
			case 'B':
			case 'b':
				morseCodeMessage.push_back("-...");
				break;
			case 'C':
			case 'c':
				morseCodeMessage.push_back("-.-.");
				break;
			case 'D':
			case 'd':
				morseCodeMessage.push_back("-..");
				break;
			case 'E':
			case 'e':
				morseCodeMessage.push_back(".");
				break;
			case 'F':
			case 'f':
				morseCodeMessage.push_back("..-.");
				break;
			case 'G':
			case 'g':
				morseCodeMessage.push_back("--.");
				break;
			case 'H':
			case 'h':
				morseCodeMessage.push_back("....");
				break;
			case 'I':
			case 'i':
				morseCodeMessage.push_back("..");
				break;
			case 'J':
			case 'j':
				morseCodeMessage.push_back(".---");
				break;
			case 'K':
			case 'k':
				morseCodeMessage.push_back("-.-");
				break;
			case 'L':
			case 'l':
				morseCodeMessage.push_back(".-..");
				break;
			case 'M':
			case 'm':
				morseCodeMessage.push_back("--");
				break;
			case 'N':
			case 'n':
				morseCodeMessage.push_back("-.");
				break;
			case 'O':
			case 'o':
				morseCodeMessage.push_back("---");
				break;
			case 'P':
			case 'p':
				morseCodeMessage.push_back(".--.");
				break;
			case 'Q':
			case 'q':
				morseCodeMessage.push_back("--.-");
				break;
			case 'R':
			case 'r':
				morseCodeMessage.push_back(".-.");
				break;
			case 'S':
			case 's':
				morseCodeMessage.push_back("...");
				break;
			case 'T':
			case 't':
				morseCodeMessage.push_back("-");
				break;
			case 'U':
			case 'u':
				morseCodeMessage.push_back("..-");
				break;
			case 'V':
			case 'v':
				morseCodeMessage.push_back("...-");
				break;
			case 'W':
			case 'w':
				morseCodeMessage.push_back(".--");
				break;
			case 'X':
			case 'x':
				morseCodeMessage.push_back("-..-");
				break;
			case 'Y':
			case 'y':
				morseCodeMessage.push_back("-.--");
				break;
			case 'Z':
			case 'z':
				morseCodeMessage.push_back("--..");
				break;
			case '1':
				morseCodeMessage.push_back(".----");
				break;
			case '2':
				morseCodeMessage.push_back("..---");
				break;
			case '3':
				morseCodeMessage.push_back("...--");
				break;
			case '4':
				morseCodeMessage.push_back("....-");
				break;
			case '5':
				morseCodeMessage.push_back(".....");
				break;
			case '6':
				morseCodeMessage.push_back("-....");
				break;
			case '7':
				morseCodeMessage.push_back("--...");
				break;
			case '8':
				morseCodeMessage.push_back("---..");
				break;
			case '9':
				morseCodeMessage.push_back("----.");
				break;
			case '0':
				morseCodeMessage.push_back("-----");
				break;
		}//translate the morse code use morse table
	}
}
void MorseCodeMessage::printMessage()
{
	cout<<"The raw message is: "<<rawMessage<<endl;//print out the raw text
	cout<<"The translated message is: "<<endl;
	for(int i; i<(int)morseCodeMessage.size();++i){
		cout<<morseCodeMessage[i]<<" ";
	}//print out the translated one
	cout<<endl;
}

class MessageStack{
	private:
		stack<Message*> stackMessage;
	public:
		MessageStack();
		MessageStack(Message* message);
		//MessageStack(Message*);
		~MessageStack();
		void pushToStack(Message*);
		void popOutStack();
		void printStack();
};

MessageStack::MessageStack()
{
	//empty constructor
}

MessageStack::MessageStack(Message* message)
{
	pushToStack(message);//parametric constructor
}

MessageStack::~MessageStack()
{
	while(!stackMessage.empty()){
		stackMessage.pop();
	}//clear all the element in the stack
}

void MessageStack::pushToStack(Message* message)
{
	stackMessage.push(message);//push object pointer to stack
}

void MessageStack::popOutStack()
{
	if(!stackMessage.empty()){
		stackMessage.pop();
		return;
	}//pop the stack when not empty
	else{
		cout<<"Cannot pop! Stack is empty!"<<endl;
	}
}

void MessageStack::printStack()
{
	if(stackMessage.empty()){
		cout<<"Stack is empty!"<<endl;
		return;
	}
	stack<Message*> temp = stackMessage;
	//create a temp stack as same as raw one
	while(!temp.empty()){
		temp.top()->printMessage();//print the top of the stack
		cout<<endl;
		temp.pop();//pop the top one
	}
}

void printOptions()
{
	cout<<"Option 1: Enter text"<<endl;
	cout<<"Option 2: Print stack"<<endl;
	cout<<"Option 3: Pop stack"<<endl;
	cout<<"Option 4: Exit"<<endl;
}

int main() {
	string text;
	int choice1;
	int choice2;
	int menuChoice;
	//vector<int> translateOrNot;//mark the text is translated or not
	//vector<string> tempMessage;//store the text temporarily
	Message globalMessage[100];
	MorseCodeMessage globalMorseCodeMessage[100];
	MessageStack messageStack;

	printOptions();
	do{
		cout<<"Enter your options: ";
		cin>>menuChoice;
		if(menuChoice == 1){
			int count = 0;
			do{
				cout<<"Please enter some text:";
				cin>>text;
				cout<<"Do you want to translate the text? Yes:1, No:0 ";
				cin>>choice1;
				if(choice1){
					MorseCodeMessage morseCodeMessage(text);
					//morseCodeMessage object will be deleted when out of scope
					globalMorseCodeMessage[count] = morseCodeMessage;
					//so we need a global one to store the object
					messageStack.pushToStack(&globalMorseCodeMessage[count]);
				}
				else{
					Message message(text);
					//morseCodeMessage object will be deleted when out of scope
					globalMessage[count] = message;
					//so we need a global one to store the object
					messageStack.pushToStack(&globalMessage[count]);
				}

				cout<<"Do you want continue? Yes:1, No:0 ";
				cin>>choice2;
				cout<<endl;
				++count;
			}while(choice2);
		}
		else if(menuChoice == 2){
			cout<<"Print out all the element in stack"<<endl;
			messageStack.printStack();//print out the stack
		}
		else if(menuChoice == 3){
			messageStack.popOutStack();
			cout<<"After pop the stack:"<<endl;
			messageStack.printStack();//print out the stack after pop the top one
		}
		else if(menuChoice == 4){
			break;//end the loop
		}
		else{
			cout<<"Wrong options! Please enter again: ";
			cin>>menuChoice;
		}
	}while(1);

	cout<<"Have a good day!"<<endl;
	return 0;
}
