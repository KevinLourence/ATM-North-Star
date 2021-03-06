﻿#ifndef STRING_ANALYZER_H
#define STRING_ANALYZER_H

#include <string>

class StringAnalyzer {
 public:
  void AnalyzeString(const std::string& string);

  int AmountOfDigits() const;
  int AmountOfAlphabeticSymbols() const;
  int AmountOfSpaces() const;

  bool IsStringContainSpecialSymbols() const;
  bool IsStringContainAdjacentSpaces() const;
  bool IsStringContainOnlyDigits() const;
  bool IsStringBeginWithSpace() const;
  bool IsStringEndWithSpace() const;
  bool IsStringEmpty() const;

 private:
  bool IsStringContainOnlyDigits(int length_of_string) const;
  bool IsStringContainSpecialSymbols(int length_of_string) const;
  bool IsStringContainAdjacentSpaces(const std::string& string) const;

  void SetToZeroValues();

  int amount_of_digits_ = 0;
  int amount_of_alphabet_symbols_ = 0;
  int amount_of_spaces_ = 0;

  bool is_special_symbols_ = true;
  bool is_begin_with_space_ = true;
  bool is_end_with_space_ = true;
  bool is_adjacent_spaces_ = true;
  bool is_only_digits_ = true;
  bool is_string_empty_ = true;

  static constexpr char space_symbol_ = ' ';
};

#endif  // STRING_ANALYZER_H
