
#include "mainwindow.h"
#include "salsa20.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_salsa = new Salsa20();
    setWindowTitle("Salsa20 Encryption App");

    // Create UI elements
    m_keyInput = new QLineEdit();
    m_textInput = new QTextEdit();
    m_textOutput = new QTextEdit();
    m_encryptButton = new QPushButton("Encrypt");
    m_decryptButton = new QPushButton("Decrypt");

    // Create layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_keyInput);
    layout->addWidget(m_textInput);
    layout->addWidget(m_encryptButton);
    layout->addWidget(m_decryptButton);
    layout->addWidget(m_textOutput);

    // Set layout to central widget
    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Connect buttons to slots
    connect(m_encryptButton, &QPushButton::clicked, this, &MainWindow::onEncryptClicked);
    connect(m_decryptButton, &QPushButton::clicked, this, &MainWindow::onDecryptClicked);
}

MainWindow::~MainWindow()
{
    delete m_salsa;
}

void MainWindow::onEncryptClicked()
{
    QString key = m_keyInput->text();
    QString text = m_textInput->toPlainText();
    if (key.isEmpty() || text.isEmpty()) {
        QMessageBox::warning(this, "Error", "Key or text is empty");
        return;
    }
    char* key_cstr = key.toUtf8().data();
    char* text_cstr = text.toUtf8().data();
    char* encryptedText = m_salsa->encrypt(key_cstr, text_cstr);
    QString encryptedQString = QString::fromUtf8(encryptedText);
    m_textOutput->setPlainText(encryptedQString);
}

void MainWindow::onDecryptClicked()
{
    QString key = m_keyInput->text();
    QString text = m_textInput->toPlainText();
    if (key.isEmpty() || text.isEmpty()) {
        QMessageBox::warning(this, "Error", "Key or text is empty");
        return;
    }
    char* key_cstr = key.toUtf8().data();
    char* text_c;
    char* decryptedText = m_salsa->decrypt(key_cstr, text_cstr);
    QString decryptedQString = QString::fromUtf8(decryptedText);
    m_textOutput->setPlainText(decryptedQString);
}
