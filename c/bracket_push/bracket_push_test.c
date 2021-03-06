#include "bracket_push.c"
#include <assert.h>

int test_paired_square_brackets() { return bracket_push_check("[]"); }

int test_empty_string() { return bracket_push_check(""); }

int test_unpaired_brackets() { return bracket_push_check("[["); }

int test_wrong_ordered_brackets() { return bracket_push_check("}{"); }

int test_wrong_closing_bracket() { return bracket_push_check("{]"); }

int test_paired_with_whitespace() { return bracket_push_check("{ }"); }

int test_simple_nested_brackets() { return bracket_push_check("{[]}"); }

int test_several_paired_brackets() { return bracket_push_check("{}[]"); }

int test_paired_nested_brackets() { return bracket_push_check("([{}({}[])])"); }

int test_unopened_closing_brackets() { return bracket_push_check("{[)][]}"); }

int test_unpaired_nested_brackets() { return bracket_push_check("([{])"); }

int test_paired_wrong_nested_brackets() { return bracket_push_check("[({]})"); }

int test_math_expression() {
  return bracket_push_check("(((185 + 223.85) * 15) - 543)/2)");
}

int test_complex_latex_expression() {
  return bracket_push_check("\\left(\\begin{array}{cc} \\frac{1}{3} & x\\\\ "
                            "\\mathrm{e}^{x} &... x^2 \\end{array}\\right)");
}

int main() {
  assert(test_paired_square_brackets() == EXIT_SUCCESS);
  assert(test_empty_string() == EXIT_SUCCESS);
  assert(test_unpaired_brackets() == EXIT_FAILURE);
  assert(test_wrong_ordered_brackets() == EXIT_FAILURE);
  assert(test_wrong_closing_bracket() == EXIT_FAILURE);
  assert(test_paired_with_whitespace() == EXIT_SUCCESS);
  assert(test_simple_nested_brackets() == EXIT_SUCCESS);
  assert(test_several_paired_brackets() == EXIT_SUCCESS);
  assert(test_paired_nested_brackets() == EXIT_SUCCESS);
  assert(test_unopened_closing_brackets() == EXIT_FAILURE);
  assert(test_unpaired_nested_brackets() == EXIT_FAILURE);
  assert(test_paired_wrong_nested_brackets() == EXIT_FAILURE);
  assert(test_math_expression() == EXIT_FAILURE);
  assert(test_complex_latex_expression() == EXIT_SUCCESS);
}