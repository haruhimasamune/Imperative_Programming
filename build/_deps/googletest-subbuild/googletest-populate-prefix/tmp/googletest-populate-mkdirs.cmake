# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/haruhimasamune/OneDrive/Desktop/Radboud/2023_S2/2324_Imperative_Programming_(KW1V)/git_repository_WIN/Imperative_Programming/build/_deps/googletest-src"
  "D:/haruhimasamune/OneDrive/Desktop/Radboud/2023_S2/2324_Imperative_Programming_(KW1V)/git_repository_WIN/Imperative_Programming/build/_deps/googletest-build"
  "D:/haruhimasamune/OneDrive/Desktop/Radboud/2023_S2/2324_Imperative_Programming_(KW1V)/git_repository_WIN/Imperative_Programming/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "D:/haruhimasamune/OneDrive/Desktop/Radboud/2023_S2/2324_Imperative_Programming_(KW1V)/git_repository_WIN/Imperative_Programming/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "D:/haruhimasamune/OneDrive/Desktop/Radboud/2023_S2/2324_Imperative_Programming_(KW1V)/git_repository_WIN/Imperative_Programming/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "D:/haruhimasamune/OneDrive/Desktop/Radboud/2023_S2/2324_Imperative_Programming_(KW1V)/git_repository_WIN/Imperative_Programming/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "D:/haruhimasamune/OneDrive/Desktop/Radboud/2023_S2/2324_Imperative_Programming_(KW1V)/git_repository_WIN/Imperative_Programming/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/haruhimasamune/OneDrive/Desktop/Radboud/2023_S2/2324_Imperative_Programming_(KW1V)/git_repository_WIN/Imperative_Programming/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/haruhimasamune/OneDrive/Desktop/Radboud/2023_S2/2324_Imperative_Programming_(KW1V)/git_repository_WIN/Imperative_Programming/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
