
#ifndef APPLICATION_H
#define APPLICATION_H
#include <list>
#include <stack>
#include"logic/user.h"
#include "logic/conversation.h"
 class Application
{
public:

    Application();

    static std::list<User*> users ;
    static User* loggedUser;
    static bool logUserIn(User& user);
    static Conversation *currentConversation ;

    static User* getLogInUser() {
        for (auto &user : Application::users)
        {
            if (user->isLoggedIn()) {
                return user ;
            }
        }
        return nullptr;
    }


    static User* searchForurUser(std::string userId) {

        for(auto *user : Application::users)
        {
            if( user != nullptr && userId == user->getUserID()) {
                return user;
            }
        }
        return nullptr;
    }

    static bool registerUser(User* user)
    {
        if(Application::isAlreadyRegistered(user)){
            return false;
        }
        Application::users.push_back(user);
        return true;
    }




    static bool isAlreadyRegistered(User* user)
    {
        std::string userID = user->getUserID();

        for(auto regUser : Application::users)
        {
            if(userID == regUser->getUserID())
                return true;
        }
        return false;
    }


    static bool loginUser(std::string id , std::string password)
    {
        if (id.empty() || password.empty()) {
            return false ;
        }

        User *targetUser = Application::searchForurUser(id);

        if(targetUser == nullptr || Application::isAlreadyLoggedIn(*targetUser) || password != targetUser->getUserPassword()){
            return false;
        }

        targetUser->setLoggedIn(true);
        return true;
    }

    static bool isAlreadyLoggedIn(User& user)
    {

        if ((&user) == nullptr || !user.isLoggedIn()) {
            return false;
        }

        return true ;
    }


    // get New Conversatoin


    static Conversation* getReceiverConversation(std::string receiverName) {
        Conversation *myConv = nullptr ;
        for (auto &user : Application::users )  {
                // Make a copy of the original stack
                std::stack<Conversation*> tempConversations ;
                // Render the copied conversations
                while (!user->getConversations().empty()) {
                    Conversation* conversationPtr = (user->getConversations().top());
                    tempConversations.push(conversationPtr);
                    user->getConversations().pop();
                }

                while(!tempConversations.empty()){
                    if (user->getUserName() != loggedUser->getUserName() && user->getUserName() == receiverName ) {
                        if (tempConversations.top()->getName() == loggedUser->getUserName()) {
                            myConv = tempConversations.top();
                        }
                    }
                    user->getConversations().push(tempConversations.top());
                    tempConversations.pop();
                }
            }

        if (myConv == nullptr) {
            for (auto &user : Application::users) {
                    if (user->getUserName() == receiverName) {
                        Contact *newContact = new Contact("fsfsa" , loggedUser->getIMGpath() , loggedUser->getUserName());
                        Conversation *newConv = new Conversation(newContact , false , loggedUser->getUserName()) ;
                        myConv = newConv ;
                        user->addNewConversation(newConv);
                        break ;
                }
            }
        }

        return myConv;
    }

    static Conversation* updatePhoto(std::string receiverName , std::string newImg) {

        for (auto &user : Application::users )  {
            // Make a copy of the original stack
            std::stack<Conversation*> tempConversations ;
            // Render the copied conversations
            while (!user->getConversations().empty()) {
                Conversation* conversationPtr = (user->getConversations().top());
                tempConversations.push(conversationPtr);
                user->getConversations().pop();
            }

            while(!tempConversations.empty()){
                if (user->getUserName() != loggedUser->getUserName() && tempConversations.top()->getReceiver()->getName() == receiverName ) {
                        tempConversations.top()->getReceiver()->setImgPath(newImg);
                }
                user->getConversations().push(tempConversations.top());
                tempConversations.pop();
            }
        }
    }

    static std::string renderWithPhoto(std::string receiverName) {

        for (auto &user : Application::users )  {
            if (user->getUserName() == receiverName) {
                return user->getIMGpath() ;
            }
        }
        return ":/imgs/Profile (2).png" ;
    }

    static QString breakText(QString& txt){

        if(txt.size() <=70) return txt;
        QString leftText = txt.mid(0,txt.size()-70);
        QString rightText = txt.mid(txt.size()-70,txt.size()-1);
        return breakText(leftText) + "\n" + breakText(rightText);
    }

    static void handleNewConversations(Conversation* conv , User* user) {

          // Make a copy of the original stack
          std::stack<Conversation*> tempConversations ;
            if (loggedUser->getConversations().empty()) {
                loggedUser->addNewConversation(conv);
                return ;
            }

            while (!loggedUser->getConversations().empty()) {
                Conversation* conversationPtr = (loggedUser->getConversations().top());
                tempConversations.push(conversationPtr);
                loggedUser->getConversations().pop();
            }

            while(!tempConversations.empty()){
                if (tempConversations.top()->getName() == conv->getName()) {
                    tempConversations.top()->setName(user->getUserName());
                }
                loggedUser->getConversations().push(tempConversations.top());
                tempConversations.pop();
            }

    }


    static QGroupBox* renderMessage(Message message){
            QHBoxLayout *hLayout = new QHBoxLayout;
            QVBoxLayout *VLayout = new QVBoxLayout ;
            QLabel *textmsg = new QLabel() ;
            textmsg->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
            textmsg->setText(QString::fromStdString(message.getMessageTxt()));
            textmsg->setTextInteractionFlags(Qt::TextSelectableByMouse);
            // Set the cursor to the I-beam cursor
            textmsg->setCursor(Qt::IBeamCursor);
            QLabel *datemsg = new QLabel();
            datemsg->setText(message.getSendDate().toString());
            QString txt = textmsg->text();
            textmsg->setText( breakText(txt));

            VLayout->addWidget(textmsg);
            VLayout->addWidget(datemsg);
            datemsg->setAlignment(Qt::AlignRight);
            datemsg->setStyleSheet("color:grey; font-size:8px");

            QGroupBox *VGroupBox = new QGroupBox();
            VLayout->setSpacing(0);
            VGroupBox->setLayout(VLayout);
            VGroupBox->setStyleSheet("background:#161a1d; font-size:17px ; color:white ;font-weight:bold ");
            QSpacerItem *hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

            if (message.getReceiverId() == loggedUser->getUserName()) {
                hLayout->addItem(hSpacer);
                hLayout->addWidget(VGroupBox);
            }
            else {
                hLayout->addWidget(VGroupBox);
                hLayout->addItem(hSpacer);
                VGroupBox->setStyleSheet("background-color :#3663fd ; font-size:17px ; color:white ;font-weight:bold ");
                 datemsg->setStyleSheet("color:white; font-size:8px");
            }
            QGroupBox *hGroupBox = new QGroupBox();
            hGroupBox->setLayout(hLayout);

            return hGroupBox;
    }


    static QClickableGroupBox* renderConversation(Conversation* conversation){

            QHBoxLayout *hLayout = new QHBoxLayout;
            QVBoxLayout *VLayout = new QVBoxLayout ;
            QHBoxLayout *hLabelChild = new QHBoxLayout ;
            QHBoxLayout *hLabelName = new QHBoxLayout ;
            QLabel *pic = new QLabel() ;

            QString IMG_PATH =QString::fromStdString(conversation->getReceiver()->getImgPath());
            QSize imgMaxSize = (IMG_PATH == ":/imgs/Profile (2).png")? *new QSize(40,40) : *new QSize(50,40);

            if(IMG_PATH == ":/imgs/Profile (2).png")
                pic->setMaximumSize(imgMaxSize);

            pic->setMinimumSize(imgMaxSize);

            QString imgType = IMG_PATH == ":/imgs/Profile (2).png"? "image" : "border-image";
            pic->setStyleSheet( imgType+  ":url(" + IMG_PATH + ");border-radius:8px");
            QLabel *senderName = new QLabel(QString::fromStdString(conversation->getName())) ;
            QLabel *textmsg = new QLabel() ;
            QString texttest = "Start Chat!";
            QSpacerItem* hchildSpacer = new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
            QSpacerItem* hchildSpacerName = new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
            hLabelName->addWidget(senderName);
            hLabelName->addItem(hchildSpacerName);
            hLabelName->setContentsMargins(0,0,0,0);
            hLabelChild->addWidget(textmsg) ;
            hLabelChild->addItem(hchildSpacer) ;
            hLabelChild->setContentsMargins(0,0,0,0);
            QGroupBox *hGroupBoxName = new QGroupBox();
            QGroupBox *hGroupBoxChild = new QGroupBox();
            hGroupBoxName->setLayout(hLabelName);
            hGroupBoxChild->setLayout(hLabelChild);
            textmsg->setStyleSheet("color:gray ; font-size :12px ");
            textmsg->setWordWrap(true);
            textmsg->setTextFormat(Qt::RichText);
            VLayout->addWidget(hGroupBoxName);
            VLayout->addWidget(hGroupBoxChild);
            int maxWidth = 130; // Maximum width in pixels
            QFont font("Arial", 12);
            QFontMetrics fontMetrics(font);
            QString elidedText = fontMetrics.elidedText(texttest, Qt::ElideRight, maxWidth);
            textmsg->setText(elidedText);
            QGroupBox *VGroupBox = new QGroupBox();
            VGroupBox->setContentsMargins(0,0,0,0);
            VLayout->setSpacing(4);
            VGroupBox->setLayout(VLayout);
            VGroupBox->setStyleSheet("background:#161a1d; font-size:15px ; color:white ;font-weight:bold ");
            hLayout->addWidget(pic);
            hLayout->addWidget(VGroupBox);

            QClickableGroupBox *hGroupBox = new QClickableGroupBox();
            hGroupBox->setLayout(hLayout);
            QSpacerItem* hSpacer = new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
            hGroupBox->layout()->addItem(hSpacer);

            QLabel *datemsg = new QLabel();
            datemsg->setText(QDate::currentDate().toString());
            datemsg->setStyleSheet("color:grey; font-size:11px ; background:transparent");

            hGroupBox->layout()->addWidget(datemsg);
            hGroupBox->setStyleSheet("QGroupBox { border:none; background :#161a1d ;border-radius : 5px;}") ;

            hGroupBox->setCursor(Qt::PointingHandCursor);
            return hGroupBox ;

    }
};

#endif // APPLICATION_H
