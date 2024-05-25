#include "text_editor.h"
#include <QTextStream>

TextEditor::TextEditor(QWidget *parent) : QMainWindow(parent), textEdit(new QTextEdit) {
    setCentralWidget(textEdit);
    createMenu();
    setWindowTitle("Text Editor");
    resize(800, 600);
}

TextEditor::~TextEditor() {
}

void TextEditor::createMenu() {
    QMenuBar *menuBar = this->menuBar();

    QMenu *fileMenu = menuBar->addMenu(tr("&File"));
    QAction *openAction = fileMenu->addAction(tr("&Open"), this, &TextEditor::openFile);
    QAction *saveAction = fileMenu->addAction(tr("&Save"), this, &TextEditor::saveFile);
    fileMenu->addSeparator();
    QAction *exitAction = fileMenu->addAction(tr("E&xit"), this, &QWidget::close);

    QMenu *helpMenu = menuBar->addMenu(tr("&Help"));
    QAction *aboutAction = helpMenu->addAction(tr("&About"), this, &TextEditor::about);
}

void TextEditor::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            currentFile = fileName;
            QTextStream in(&file);
            textEdit->setPlainText(in.readAll());
        } else {
            QMessageBox::warning(this, tr("Error"), tr("Cannot open file: ") + file.errorString());
        }
    }
}

void TextEditor::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::WriteOnly | QFile::Text)) {
            currentFile = fileName;
            QTextStream out(&file);
            out << textEdit->toPlainText();
        } else {
            QMessageBox::warning(this, tr("Error"), tr("Cannot save file: ") + file.errorString());
        }
    }
}

void TextEditor::about() {
    QMessageBox::about(this, tr("About Text Editor"),
            tr("A simple text editor built with Qt."));
}
