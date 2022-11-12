/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_startScreen;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_startScreenUp;
    QGridLayout *gridLayout_startScreen;
    QPushButton *pushButton_start;
    QLabel *label_ticTacToe;
    QSpacerItem *horizontalSpacer_startScreenLeft;
    QSpacerItem *horizontalSpacer_startScreenRight;
    QSpacerItem *verticalSpacer_startScreenMiddle;
    QSpacerItem *verticalSpacer_startScreenBottom;
    QWidget *page_freeFormSetup;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_freeFormSetupLeft;
    QSpacerItem *verticalSpacer_freeFormSetupDown;
    QSpacerItem *horizontalSpacer_freeFormSetupRight;
    QGridLayout *gridLayout_setupSettings;
    QVBoxLayout *verticalLayout_boardsSettings;
    QGridLayout *gridLayout_boardNumSettings;
    QSpacerItem *verticalSpacer_board1SettingsUp;
    QSpinBox *spinBox_numberOfRounds;
    QLabel *label_x;
    QLabel *label_inARowToWin;
    QLabel *label_sizeOfBoard;
    QSpinBox *spinBox_inARowToWin;
    QSpinBox *spinBox_sizeOfBoard1;
    QPushButton *pushButton_makeAllBoardsLikeThis;
    QLabel *label_editBoardNum;
    QSpinBox *spinBox_sizeOfBoard2;
    QLabel *label_numberOfRounds;
    QSpacerItem *horizontalSpacer_setupSettingsLeft;
    QLabel *label_numberOfPlayers;
    QFrame *line_gameSetupDown;
    QFrame *line;
    QFrame *line_startGameUp;
    QHBoxLayout *horizontalLayout_freeFormSetupUp;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_playerSymbols;
    QHBoxLayout *horizontalLayout_player1Symbol;
    QLineEdit *lineEdit_player1Name;
    QLineEdit *lineEdit_player1Symbol;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_player2Symbol;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_player2Symbol;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_startGame;
    QPushButton *pushButton_startGame;
    QHBoxLayout *horizontalLayout_gameSetup;
    QSpacerItem *horizontalSpacer_gameSetupLeft;
    QLabel *label_gameSetup;
    QSpacerItem *horizontalSpacer_gameSetupRight;
    QSpinBox *spinBox_numberOfPlayers;
    QHBoxLayout *horizontalLayout_freeFormTTT;
    QSpacerItem *horizontalSpacer_freeFormTTTLeft;
    QLabel *label_freeFormTTT;
    QSpacerItem *horizontalSpacer_freeFormTTTRight;
    QSpinBox *spinBox_numberOfBoards;
    QSpacerItem *horizontalSpacer_setupSettingsRight;
    QLabel *label_numberOfBoards;
    QLabel *label_name;
    QLabel *label_symbol;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(437, 558);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(9999, 9999));
        QFont font;
        font.setStrikeOut(false);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_startScreen = new QWidget();
        page_startScreen->setObjectName(QString::fromUtf8("page_startScreen"));
        page_startScreen->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(page_startScreen->sizePolicy().hasHeightForWidth());
        page_startScreen->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(page_startScreen);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_startScreenUp = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_2->addItem(verticalSpacer_startScreenUp, 0, 1, 1, 1);

        gridLayout_startScreen = new QGridLayout();
        gridLayout_startScreen->setObjectName(QString::fromUtf8("gridLayout_startScreen"));
        gridLayout_startScreen->setVerticalSpacing(6);
        pushButton_start = new QPushButton(page_startScreen);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setMinimumSize(QSize(128, 0));

        gridLayout_startScreen->addWidget(pushButton_start, 2, 1, 1, 1);

        label_ticTacToe = new QLabel(page_startScreen);
        label_ticTacToe->setObjectName(QString::fromUtf8("label_ticTacToe"));
        label_ticTacToe->setMinimumSize(QSize(0, 0));
        label_ticTacToe->setMaximumSize(QSize(16777215, 24));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        font1.setKerning(false);
        font1.setStyleStrategy(QFont::PreferDefault);
        label_ticTacToe->setFont(font1);
        label_ticTacToe->setAlignment(Qt::AlignCenter);

        gridLayout_startScreen->addWidget(label_ticTacToe, 0, 1, 1, 1);

        horizontalSpacer_startScreenLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_startScreen->addItem(horizontalSpacer_startScreenLeft, 0, 0, 4, 1);

        horizontalSpacer_startScreenRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_startScreen->addItem(horizontalSpacer_startScreenRight, 0, 2, 4, 1);

        verticalSpacer_startScreenMiddle = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_startScreen->addItem(verticalSpacer_startScreenMiddle, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_startScreen, 2, 1, 1, 1);

        verticalSpacer_startScreenBottom = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_startScreenBottom, 5, 1, 1, 1);

        stackedWidget->addWidget(page_startScreen);
        page_freeFormSetup = new QWidget();
        page_freeFormSetup->setObjectName(QString::fromUtf8("page_freeFormSetup"));
        gridLayout_3 = new QGridLayout(page_freeFormSetup);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_freeFormSetupLeft = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_freeFormSetupLeft, 7, 0, 1, 1);

        verticalSpacer_freeFormSetupDown = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_freeFormSetupDown, 11, 1, 1, 2);

        horizontalSpacer_freeFormSetupRight = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_freeFormSetupRight, 7, 3, 1, 1);

        gridLayout_setupSettings = new QGridLayout();
        gridLayout_setupSettings->setObjectName(QString::fromUtf8("gridLayout_setupSettings"));
        verticalLayout_boardsSettings = new QVBoxLayout();
        verticalLayout_boardsSettings->setObjectName(QString::fromUtf8("verticalLayout_boardsSettings"));
        gridLayout_boardNumSettings = new QGridLayout();
        gridLayout_boardNumSettings->setObjectName(QString::fromUtf8("gridLayout_boardNumSettings"));
        gridLayout_boardNumSettings->setHorizontalSpacing(6);
        verticalSpacer_board1SettingsUp = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_boardNumSettings->addItem(verticalSpacer_board1SettingsUp, 0, 0, 1, 4);

        spinBox_numberOfRounds = new QSpinBox(page_freeFormSetup);
        spinBox_numberOfRounds->setObjectName(QString::fromUtf8("spinBox_numberOfRounds"));
        spinBox_numberOfRounds->setMinimumSize(QSize(42, 0));
        spinBox_numberOfRounds->setMaximumSize(QSize(42, 16777215));
        spinBox_numberOfRounds->setValue(1);

        gridLayout_boardNumSettings->addWidget(spinBox_numberOfRounds, 4, 1, 1, 3);

        label_x = new QLabel(page_freeFormSetup);
        label_x->setObjectName(QString::fromUtf8("label_x"));
        label_x->setMinimumSize(QSize(0, 0));
        label_x->setMaximumSize(QSize(10, 16777215));

        gridLayout_boardNumSettings->addWidget(label_x, 2, 2, 1, 1);

        label_inARowToWin = new QLabel(page_freeFormSetup);
        label_inARowToWin->setObjectName(QString::fromUtf8("label_inARowToWin"));

        gridLayout_boardNumSettings->addWidget(label_inARowToWin, 3, 0, 1, 1);

        label_sizeOfBoard = new QLabel(page_freeFormSetup);
        label_sizeOfBoard->setObjectName(QString::fromUtf8("label_sizeOfBoard"));

        gridLayout_boardNumSettings->addWidget(label_sizeOfBoard, 2, 0, 1, 1);

        spinBox_inARowToWin = new QSpinBox(page_freeFormSetup);
        spinBox_inARowToWin->setObjectName(QString::fromUtf8("spinBox_inARowToWin"));
        spinBox_inARowToWin->setMinimumSize(QSize(42, 0));
        spinBox_inARowToWin->setMaximumSize(QSize(42, 16777215));
        spinBox_inARowToWin->setValue(3);

        gridLayout_boardNumSettings->addWidget(spinBox_inARowToWin, 3, 1, 1, 3);

        spinBox_sizeOfBoard1 = new QSpinBox(page_freeFormSetup);
        spinBox_sizeOfBoard1->setObjectName(QString::fromUtf8("spinBox_sizeOfBoard1"));
        spinBox_sizeOfBoard1->setMinimumSize(QSize(42, 0));
        spinBox_sizeOfBoard1->setMaximumSize(QSize(42, 16777215));
        spinBox_sizeOfBoard1->setMinimum(0);

        gridLayout_boardNumSettings->addWidget(spinBox_sizeOfBoard1, 2, 1, 1, 1);

        pushButton_makeAllBoardsLikeThis = new QPushButton(page_freeFormSetup);
        pushButton_makeAllBoardsLikeThis->setObjectName(QString::fromUtf8("pushButton_makeAllBoardsLikeThis"));
        pushButton_makeAllBoardsLikeThis->setMinimumSize(QSize(42, 0));
        pushButton_makeAllBoardsLikeThis->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_boardNumSettings->addWidget(pushButton_makeAllBoardsLikeThis, 1, 1, 1, 3);

        label_editBoardNum = new QLabel(page_freeFormSetup);
        label_editBoardNum->setObjectName(QString::fromUtf8("label_editBoardNum"));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        label_editBoardNum->setFont(font2);

        gridLayout_boardNumSettings->addWidget(label_editBoardNum, 1, 0, 1, 1);

        spinBox_sizeOfBoard2 = new QSpinBox(page_freeFormSetup);
        spinBox_sizeOfBoard2->setObjectName(QString::fromUtf8("spinBox_sizeOfBoard2"));
        spinBox_sizeOfBoard2->setMinimumSize(QSize(42, 0));
        spinBox_sizeOfBoard2->setMaximumSize(QSize(42, 16777215));
        spinBox_sizeOfBoard2->setValue(3);

        gridLayout_boardNumSettings->addWidget(spinBox_sizeOfBoard2, 2, 3, 1, 1);

        label_numberOfRounds = new QLabel(page_freeFormSetup);
        label_numberOfRounds->setObjectName(QString::fromUtf8("label_numberOfRounds"));

        gridLayout_boardNumSettings->addWidget(label_numberOfRounds, 4, 0, 1, 1);


        verticalLayout_boardsSettings->addLayout(gridLayout_boardNumSettings);


        gridLayout_setupSettings->addLayout(verticalLayout_boardsSettings, 14, 1, 5, 4);

        horizontalSpacer_setupSettingsLeft = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_setupSettings->addItem(horizontalSpacer_setupSettingsLeft, 6, 0, 14, 1);

        label_numberOfPlayers = new QLabel(page_freeFormSetup);
        label_numberOfPlayers->setObjectName(QString::fromUtf8("label_numberOfPlayers"));

        gridLayout_setupSettings->addWidget(label_numberOfPlayers, 6, 1, 1, 1);

        line_gameSetupDown = new QFrame(page_freeFormSetup);
        line_gameSetupDown->setObjectName(QString::fromUtf8("line_gameSetupDown"));
        line_gameSetupDown->setMinimumSize(QSize(0, 12));
        line_gameSetupDown->setMaximumSize(QSize(512, 16777215));
        line_gameSetupDown->setFrameShadow(QFrame::Plain);
        line_gameSetupDown->setFrameShape(QFrame::HLine);

        gridLayout_setupSettings->addWidget(line_gameSetupDown, 5, 0, 1, 6);

        line = new QFrame(page_freeFormSetup);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 12));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        gridLayout_setupSettings->addWidget(line, 11, 1, 1, 4);

        line_startGameUp = new QFrame(page_freeFormSetup);
        line_startGameUp->setObjectName(QString::fromUtf8("line_startGameUp"));
        line_startGameUp->setMinimumSize(QSize(0, 12));
        line_startGameUp->setMaximumSize(QSize(512, 16777215));
        line_startGameUp->setFrameShadow(QFrame::Plain);
        line_startGameUp->setFrameShape(QFrame::HLine);

        gridLayout_setupSettings->addWidget(line_startGameUp, 20, 0, 1, 6);

        horizontalLayout_freeFormSetupUp = new QHBoxLayout();
        horizontalLayout_freeFormSetupUp->setObjectName(QString::fromUtf8("horizontalLayout_freeFormSetupUp"));
        pushButton = new QPushButton(page_freeFormSetup);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(40, 20));

        horizontalLayout_freeFormSetupUp->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_freeFormSetupUp->addItem(horizontalSpacer);


        gridLayout_setupSettings->addLayout(horizontalLayout_freeFormSetupUp, 1, 0, 1, 6);

        verticalLayout_playerSymbols = new QVBoxLayout();
        verticalLayout_playerSymbols->setObjectName(QString::fromUtf8("verticalLayout_playerSymbols"));
        horizontalLayout_player1Symbol = new QHBoxLayout();
        horizontalLayout_player1Symbol->setObjectName(QString::fromUtf8("horizontalLayout_player1Symbol"));
        lineEdit_player1Name = new QLineEdit(page_freeFormSetup);
        lineEdit_player1Name->setObjectName(QString::fromUtf8("lineEdit_player1Name"));

        horizontalLayout_player1Symbol->addWidget(lineEdit_player1Name);

        lineEdit_player1Symbol = new QLineEdit(page_freeFormSetup);
        lineEdit_player1Symbol->setObjectName(QString::fromUtf8("lineEdit_player1Symbol"));
        lineEdit_player1Symbol->setMinimumSize(QSize(42, 0));
        lineEdit_player1Symbol->setMaximumSize(QSize(42, 16777215));
        QFont font3;
        font3.setPointSize(10);
        font3.setStrikeOut(false);
        lineEdit_player1Symbol->setFont(font3);

        horizontalLayout_player1Symbol->addWidget(lineEdit_player1Symbol);

        horizontalSpacer_3 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_player1Symbol->addItem(horizontalSpacer_3);


        verticalLayout_playerSymbols->addLayout(horizontalLayout_player1Symbol);

        horizontalLayout_player2Symbol = new QHBoxLayout();
        horizontalLayout_player2Symbol->setObjectName(QString::fromUtf8("horizontalLayout_player2Symbol"));
        horizontalLayout_player2Symbol->setContentsMargins(-1, 0, -1, -1);
        lineEdit = new QLineEdit(page_freeFormSetup);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_player2Symbol->addWidget(lineEdit);

        lineEdit_player2Symbol = new QLineEdit(page_freeFormSetup);
        lineEdit_player2Symbol->setObjectName(QString::fromUtf8("lineEdit_player2Symbol"));
        lineEdit_player2Symbol->setMinimumSize(QSize(42, 0));
        lineEdit_player2Symbol->setMaximumSize(QSize(42, 16777215));

        horizontalLayout_player2Symbol->addWidget(lineEdit_player2Symbol);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_player2Symbol->addItem(horizontalSpacer_2);


        verticalLayout_playerSymbols->addLayout(horizontalLayout_player2Symbol);


        gridLayout_setupSettings->addLayout(verticalLayout_playerSymbols, 8, 1, 1, 4);

        horizontalLayout_startGame = new QHBoxLayout();
        horizontalLayout_startGame->setObjectName(QString::fromUtf8("horizontalLayout_startGame"));
        horizontalLayout_startGame->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton_startGame = new QPushButton(page_freeFormSetup);
        pushButton_startGame->setObjectName(QString::fromUtf8("pushButton_startGame"));
        pushButton_startGame->setMinimumSize(QSize(120, 30));
        pushButton_startGame->setMaximumSize(QSize(120, 30));

        horizontalLayout_startGame->addWidget(pushButton_startGame);


        gridLayout_setupSettings->addLayout(horizontalLayout_startGame, 21, 0, 1, 6);

        horizontalLayout_gameSetup = new QHBoxLayout();
        horizontalLayout_gameSetup->setObjectName(QString::fromUtf8("horizontalLayout_gameSetup"));
        horizontalSpacer_gameSetupLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_gameSetup->addItem(horizontalSpacer_gameSetupLeft);

        label_gameSetup = new QLabel(page_freeFormSetup);
        label_gameSetup->setObjectName(QString::fromUtf8("label_gameSetup"));
        QFont font4;
        font4.setPointSize(14);
        font4.setStrikeOut(false);
        label_gameSetup->setFont(font4);

        horizontalLayout_gameSetup->addWidget(label_gameSetup);

        horizontalSpacer_gameSetupRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_gameSetup->addItem(horizontalSpacer_gameSetupRight);


        gridLayout_setupSettings->addLayout(horizontalLayout_gameSetup, 4, 0, 1, 6);

        spinBox_numberOfPlayers = new QSpinBox(page_freeFormSetup);
        spinBox_numberOfPlayers->setObjectName(QString::fromUtf8("spinBox_numberOfPlayers"));
        spinBox_numberOfPlayers->setMinimumSize(QSize(42, 0));
        spinBox_numberOfPlayers->setMaximumSize(QSize(42, 16777215));
        spinBox_numberOfPlayers->setFocusPolicy(Qt::WheelFocus);
        spinBox_numberOfPlayers->setLayoutDirection(Qt::LeftToRight);
        spinBox_numberOfPlayers->setReadOnly(false);
        spinBox_numberOfPlayers->setMinimum(0);
        spinBox_numberOfPlayers->setMaximum(26);
        spinBox_numberOfPlayers->setValue(2);

        gridLayout_setupSettings->addWidget(spinBox_numberOfPlayers, 6, 2, 1, 3);

        horizontalLayout_freeFormTTT = new QHBoxLayout();
        horizontalLayout_freeFormTTT->setObjectName(QString::fromUtf8("horizontalLayout_freeFormTTT"));
        horizontalSpacer_freeFormTTTLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_freeFormTTT->addItem(horizontalSpacer_freeFormTTTLeft);

        label_freeFormTTT = new QLabel(page_freeFormSetup);
        label_freeFormTTT->setObjectName(QString::fromUtf8("label_freeFormTTT"));
        QFont font5;
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setWeight(75);
        font5.setStrikeOut(false);
        label_freeFormTTT->setFont(font5);

        horizontalLayout_freeFormTTT->addWidget(label_freeFormTTT);

        horizontalSpacer_freeFormTTTRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_freeFormTTT->addItem(horizontalSpacer_freeFormTTTRight);


        gridLayout_setupSettings->addLayout(horizontalLayout_freeFormTTT, 3, 0, 1, 6);

        spinBox_numberOfBoards = new QSpinBox(page_freeFormSetup);
        spinBox_numberOfBoards->setObjectName(QString::fromUtf8("spinBox_numberOfBoards"));
        spinBox_numberOfBoards->setMinimumSize(QSize(42, 0));
        spinBox_numberOfBoards->setMaximumSize(QSize(42, 16777215));
        spinBox_numberOfBoards->setMinimum(1);
        spinBox_numberOfBoards->setValue(1);

        gridLayout_setupSettings->addWidget(spinBox_numberOfBoards, 12, 2, 2, 3);

        horizontalSpacer_setupSettingsRight = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_setupSettings->addItem(horizontalSpacer_setupSettingsRight, 6, 5, 14, 1);

        label_numberOfBoards = new QLabel(page_freeFormSetup);
        label_numberOfBoards->setObjectName(QString::fromUtf8("label_numberOfBoards"));

        gridLayout_setupSettings->addWidget(label_numberOfBoards, 12, 1, 2, 1);

        label_name = new QLabel(page_freeFormSetup);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        gridLayout_setupSettings->addWidget(label_name, 7, 1, 1, 1);

        label_symbol = new QLabel(page_freeFormSetup);
        label_symbol->setObjectName(QString::fromUtf8("label_symbol"));

        gridLayout_setupSettings->addWidget(label_symbol, 7, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_setupSettings, 7, 1, 1, 2);

        stackedWidget->addWidget(page_freeFormSetup);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label_ticTacToe->setText(QCoreApplication::translate("MainWindow", "Free Form Tic-Tac-Toe", nullptr));
        label_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        label_inARowToWin->setText(QCoreApplication::translate("MainWindow", "In a row to win:", nullptr));
        label_sizeOfBoard->setText(QCoreApplication::translate("MainWindow", "Size of board:", nullptr));
        pushButton_makeAllBoardsLikeThis->setText(QCoreApplication::translate("MainWindow", "Sync to All", nullptr));
        label_editBoardNum->setText(QCoreApplication::translate("MainWindow", "Board 1 settings", nullptr));
        label_numberOfRounds->setText(QCoreApplication::translate("MainWindow", "Number of rounds:", nullptr));
        label_numberOfPlayers->setText(QCoreApplication::translate("MainWindow", "Number of players:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        lineEdit_player1Name->setText(QCoreApplication::translate("MainWindow", "Player 1", nullptr));
        lineEdit_player1Symbol->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        lineEdit_player1Symbol->setPlaceholderText(QString());
        lineEdit->setText(QCoreApplication::translate("MainWindow", "Player 2", nullptr));
        lineEdit_player2Symbol->setText(QCoreApplication::translate("MainWindow", "o", nullptr));
        pushButton_startGame->setText(QCoreApplication::translate("MainWindow", "Start Game", nullptr));
        label_gameSetup->setText(QCoreApplication::translate("MainWindow", "Game Setup", nullptr));
        label_freeFormTTT->setText(QCoreApplication::translate("MainWindow", "Free Form Tic-Tac-Toe", nullptr));
        label_numberOfBoards->setText(QCoreApplication::translate("MainWindow", "Number of boards:", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_symbol->setText(QCoreApplication::translate("MainWindow", "Symbol:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
