#pragma once
#include <vector>

/**
 * @brief Renders the snake
 */
bool receiveUserInput();

/**
 * @brief Receives the Input from Keyboard & returns direction|
 *        cancelation
 */
std::string render();

std::vector<std::vector<int>> calculatePositionSnake();
std::vector<int> calculatePositionApple();
std::vector<int> getScreenSize();
void calculateSnakeHeadPosition(std::vector<int> &currPos, int ch);

bool checkWindowSizeEnough();
bool abortProgram();
bool continueProgram();
void printWhiteSpace(int y, int x);
void printNewLine(int y, int x);
void renderBorder(int maxY, int maxX);
void renderSnake(int y, int x);
