

#define CATCH_CONFIG_MAIN
#include "CatchMain.h"
#include "catch.hpp"

// #define CATCH_CONFIG_RUNNER // This tells Catch we provide main.
// #include "CatchMain.h"
// #include "catch.hpp"

// // Global! Only do this in a private test harness.
// namespace lrg
// {
//     int argc;
//     char **argv;
// } // namespace lrg

// int main(int argc, char *const argv[])
// {
//     lrg::argc = argc;
//     lrg::argv = const_cast<char **>(argv);

//     Catch::Session session; // There must be exactly once instance

//     int tmpArgc = 1;
//     char *tmpCommandName = new char[256];
//     strcpy(tmpCommandName, argv[0]);

//     int returnCode = session.applyCommandLine(tmpArgc, const_cast<char **>(&tmpCommandName));
//     if (returnCode != 0) // Indicates a command line error
//         return returnCode;

//     int sessionReturnCode = session.run();

//     delete[] tmpCommandName;
//     return sessionReturnCode;
// }
