#include <SDL2/SDL.h>

void die(const char *format, ...) {
  va_list args;
  va_start(args, format);
  SDL_LogMessageV(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, format,
                  args);
  va_end(args);
  exit(EXIT_FAILURE);
}
