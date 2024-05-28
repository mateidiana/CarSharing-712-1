set(HEADER_FILES Employee.h)

set(SOURCE_FILES Employee.cpp)

add_library(EmployeeLib STATIC ${SOURCE_FILES} ${HEADER_FILES})