#ifndef OUTPUTSETUP_H
#define OUTPUTSETUP_H

#include <string>

#include "multiwriter.h"

class OutputSetup {
 public:
  static void SetupTwoStreamsForOutput();

 private:
  static void SetVectorForOutput(std::unique_ptr<Writer> console_output,
                                 std::unique_ptr<Writer> file_output);

  static void SetMultistream(
      std::vector<std::unique_ptr<Writer>> output_vector);

  static std::string name_of_file_;
};

#endif  // OUTPUTSETUP_H
