module;
#include <macro.h>
export module Base;

export ARK_API void hello() {
  //Example of an in-line module function definition.
}

export ARK_API void test();

export ARK_API void test2();

export struct bop {
  int dop;
};

module :private;
void test2()
{
  //Example of an in-line module function definition that is private and doesn't cause a recompilation.
}

/*
 * See
 * https://www.modernescpp.com/index.php/cpp20-modules/
 * https://vector-of-bool.github.io/2019/10/07/modules-3.html
 */