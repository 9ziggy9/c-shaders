#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <panic.h>

GLFWwindow *init_win(void) {
  if (!glfwInit()) PANIC_WITH(WIN_INIT_FAIL);
  GLFWwindow *w = glfwCreateWindow(960, 720, "shadies", NULL, NULL);
  if (!w) {
    glfwTerminate();
    PANIC_WITH(WIN_ALLOC_FAIL);
  }
  return w;
}

void handle_keys(GLFWwindow *w, int key, int cd, int act, int mods)
{
  (void) cd; (void) mods;
  if (key == GLFW_KEY_ESCAPE && act == GLFW_PRESS) {
    fprintf(stdout, "Exiting cleanly :)\n");
    glfwSetWindowShouldClose(w, GLFW_TRUE);
  }
}

int main(void) {
  GLFWwindow *win = init_win();
  glfwMakeContextCurrent(win);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    PANIC_WITH(GLAD_INIT_FAIL);
  }

  glfwSetKeyCallback(win, handle_keys);

  while (!glfwWindowShouldClose(win)) {
    glClear(GL_COLOR_BUFFER_BIT);

    // render here

    glfwSwapBuffers(win);
    glfwPollEvents();
  }

  glfwDestroyWindow(win);
  glfwTerminate();
  return 0;
}
