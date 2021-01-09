#include "log.h"
#include <SDL2/SDL.h>

namespace {
const char *main_window_title = "GoldenEye 007";
SDL_Window *main_window;
} // namespace

void create_main_window() {
  main_window = SDL_CreateWindow(main_window_title, SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED, 640, 480,
                                 SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_GRABBED);
  if (nullptr == main_window) {
    die("Could not create a new window: %s", SDL_GetError());
  }
}

void init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    die("Could not initialize SDL: %s", SDL_GetError());
  }
}

int main() {
  init();
  atexit([]() { SDL_Quit(); });
  create_main_window();
  return EXIT_SUCCESS;
}
