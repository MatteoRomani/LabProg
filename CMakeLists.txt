cmake_minimum_required(VERSION 3.20)
project(LabProg)

set(CMAKE_CXX_STANDARD 14)

#START wxWidget
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})
#END wxWidget

#START googleTest
add_subdirectory(googleTest)
set(SOURCE_FILES Observer.h Subject.h Observer.cpp MaxFormula.cpp MaxFormula.h MinFormula.cpp MinFormula.h MeanFormula.cpp MeanFormula.h SumFormula.cpp SumFormula.h Cell.cpp Cell.h)
add_executable(LabProg Observer.h Subject.h Observer.cpp MaxFormula.cpp MaxFormula.h MinFormula.cpp MinFormula.h MeanFormula.cpp MeanFormula.h SumFormula.cpp SumFormula.h Cell.cpp Cell.h MyApp.cpp MyApp.h MyFrame.cpp MyFrame.h Subject.cpp)
add_library(core ${SOURCE_FILES})
#END googleTest

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_link_libraries(LabProg core)