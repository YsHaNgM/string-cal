add_library(stringcal shuntingYard.cpp shuntingYard.h generator.h)


target_link_libraries(stringcal ${ALL_THIRD_PARTY_LIBRARIES})
# target_link_options(stringcal -fcoroutines)
