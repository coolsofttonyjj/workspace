CXX := g++ -g
CXXFLAGS := -std=c++11
BUILD_PATH := ./.obj
SRCS := $(wildcard *.cpp)
TARGET := $(SRCS:%.cpp=%)
DEPS := $(SRCS:%.cpp=$(BUILD_PATH)/%.d)
OBJS := $(SRCS:%.cpp=$(BUILD_PATH)/%.o)

all : $(TARGET)
	@echo "编译完成"

$(TARGET) : % : $(BUILD_PATH)/%.o
	@echo "编译 $@"
	$(CXX) $(CXXFLAGS) $< -o $@;

$(BUILD_PATH)/%.o : %.cpp
	@echo "编译 $@";
	@if [ ! -d $(BUILD_PATH) ]; then \
		mkdir -pv $(BUILD_PATH); \
	fi
	$(CXX) -c $(CXXFLAGS) $< -o $@;

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
	@rm -rf $(TARGET) $(BUILD_PATH)

.PHONY : all clean
