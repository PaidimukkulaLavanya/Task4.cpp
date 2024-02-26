#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib> // For system() function

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void speak(const string& phrase) {
    string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
    system(charCommand);
}

void wishme() {
    time_t now = time(0);
    tm *time = localtime(&now);

    if (time->tm_hour < 12) {
        cout << "Good Morning Sir" << endl;
        speak("Good Morning Sir");
    } else if (time->tm_hour >= 12 && time->tm_hour <= 16) {
        cout << "Good Afternoon sir" << endl;
        speak("Good Afternoon sir");
    } else if (time->tm_hour > 16 && time->tm_hour < 24) {
        cout << "Good Evening sir" << endl;
        speak("Good Evening sir");
    }
}

void datetime() {
    time_t now = time(0);
    char *dt = ctime(&now);
    cout << "The date and time is " << endl << dt << endl;
}

int main() {
    cout << "\t\t\t<============================================= W E L C O M E ==========================================>" << endl;
    cout << "\t\t\t<============================================= I'M A VIRTUAL ASSISTANT ==========================================>" << endl;
    cout << "\t\t\t<============================================= MY NAME IS Aditi ==========================================>" << endl;
    cout << "\t\t\t<============================================= I'M HERE TO HELP YOU ==========================================>" << endl << endl;

    string password;
    string ch;

    do {
        cout << "=======================" << endl;
        cout << "| ENTER YOUR PASSWORD |" << endl;
        cout << "=======================" << endl << endl;
        speak("Please enter your password");

        getline(cin, password);

        if (password == "password") {
            cout << "\n<==================================================================================================>\n\n";
            wishme();
            do {
                cout << "\n<==================================================================================================>\n\n";
                cout << endl << "How can I help you sir...." << endl << endl;
                speak("How can I help you sir");

                cout << "Your query ===> ";
                getline(cin, ch);
                cout << endl;
                cout << "Here is the result for your query ===> ";

                if (ch == "hi" || ch == "hey" || ch == "hello") {
                    cout << "Hello sir....." << endl;
                    speak("Hello sir");
                } else if (ch == "bye" || ch == "stop" || ch == "exit") {
                    cout << "Good Bye sir, have a nice day!!!!" << endl;
                    speak("Good Bye sir, have a nice day");
                    exit(0);
                } else if (ch == "who are you" || ch == "tell me about yourself" || ch == "about") {
                    cout << "I'm a virtual assistant created by Aditi !!!" << endl;
                    speak("I am a virtual assistant created by Aditi");
                } else if (ch == "how are you" || ch == "whatsup" || ch == "how is your day") {
                    cout << "I'm good sir, tell me how can I help you.." << endl;
                    speak("I'm good sir, tell me how can I help you");
                } else if (ch == "time" || ch == "date") {
                    datetime();
                } else if (ch == "open notepad") {
                    cout << "Opening notepad....." << endl;
                    speak("Opening notepad");
                    system("notepad");
                } else if (ch == "open google") {
                    cout << "Opening Google....." << endl;
                    speak("Opening Google");
                    system("start https://www.google.com");
                } else if (ch == "open youtube") {
                    cout << "Opening YouTube....." << endl;
                    speak("Opening YouTube");
                    system("start https://www.youtube.com");
                } else if (ch == "open instagram") {
                    cout << "Opening Instagram....." << endl;
                    speak("Opening Instagram");
                    system("start https://www.instagram.com");
                } else {
                    cout << "Sorry, could not understand your query. Please try again!!!" << endl;
                    speak("Sorry, could not understand your query. Please try again");
                }

            } while (true);
        } else {
            cout << "\t\t\t<============================= W E L C O M E=============================>" << endl;
            cout << "\t\t\t<============================= I'M VIRTUAL ASSISTANT =============================>" << endl;
            cout << "\t\t\t<============================= MY NAME IS Aditi =============================>" << endl;
            cout << "\t\t\t<============================= I'M HERE TO HELP YOU AND MAKE YOUR LIFE EASY =============================>" << endl << endl;
            cout << "======================" << endl;
            cout << "X Incorrect Password X" << endl;
            cout << "======================" << endl << endl;
            speak("Incorrect Password, Please enter correct password");
        }
    } while (true);

    return 0;
}
