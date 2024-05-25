#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>

class TextEditor : public QMainWindow {
    Q_OBJECT

public:
    TextEditor(QWidget *parent = nullptr);
    ~TextEditor();

private slots:
    void openFile();
    void saveFile();
    void about();

private:
    void createMenu();
    QTextEdit *textEdit;
    QString currentFile;
};

#endif // TEXT_EDITOR_H
