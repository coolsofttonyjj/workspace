CXX := g++
CXXFLAGS := -g -I -Wall -std=gnu++11
BUILD_PATH := ./.obj
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=$(BUILD_PATH)/%.o)
DEPS := $(SRCS:%.cpp=$(BUILD_PATH)/%.d)
TARGETS := $(SRCS:%.cpp=%)

all : $(TARGETS)
	@echo "编译完成";

$(TARGETS) : % : $(BUILD_PATH)/%.o
	@echo "编译 $@";
	@$(CXX) $(CXXFLAGS) $< -o $@;

$(BUILD_PATH)/%.o: %.cpp
	@echo "编译 $@";
	@$(CXX) -c $(CXXFLAGS) $< -o $@;

-include $(DEPS)
$(BUILD_PATH)/%.d : %.cpp 
	@echo "生成 $@"; 
	@if [ ! -d $(BUILD_PATH) ]; then \
		mkdir -pv $(BUILD_PATH); \
	fi
	@$(CC) -M $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;\
	rm -f $@.$$$$;

clean:
	@rm -rf $(TARGETS) $(BUILD_PATH)

.PHONY : clean
