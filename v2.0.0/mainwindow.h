#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include "salsa20.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onEncryptClicked();
    void onDecryptClicked();

private:
    QLineEdit *m_keyInput;
    QTextEdit *m_textInput;
    QTextEdit *m_textOutput;
    QPushButton *m_encryptButton;
    QPushButton *m_decryptButton;
    Salsa20 *m_salsa;
};
#endif
