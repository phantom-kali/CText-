# Graphical Text Editor

A simple graphical text editor built with C++ and Qt.

## Features

- Open and save text files
- Basic text editing functionalities
- Simple and intuitive user interface

## Prerequisites

- C++ compiler (g++)
- Qt5 libraries
- CMake

## Setup Instructions

1. **Clone the repository:**
    ```sh
    git clone https://github.com/phantom-kali/CText-.git
    cd CText-
    ```

2. **Install Qt5:**
    - On Ubuntu/Debian:
        ```sh
        sudo apt-get install qt5-default
        ```
    - On Fedora:
        ```sh
        sudo dnf install qt5-qtbase-devel
        ```
    - On Arch Linux:
        ```sh
        sudo pacman -S qt5-base
        ```
    - Alternatively, you can download Qt5 from the [official website](https://www.qt.io/download).

3. **Build the project:**
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

4. **Run the application:**
    ```sh
    ./graphical_text_editor
    ```

## Usage

- **Open File:** Use the `File` menu to open a text file.
- **Save File:** Use the `File` menu to save the current text to a file.
- **About:** Use the `Help` menu to see information about the application.
