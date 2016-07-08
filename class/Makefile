CXX := g++
CXXFLAGS := -g -I -Wall -std=gnu++11
BUILD_PATH := ./.obj
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=$(BUILD_PATH)/%.o)
DEPS := $(SRCS:%.cpp=$(BUILD_PATH)/%.d)
TARGET := client

all : $(TARGET)
	@echo "编译完成"

$(TARGET) : $(OBJS)
	@echo "编译 $@";
	@rm -rf $(TARGET);
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@;

$(OBJS) : $(BUILD_PATH)/%.o : %.cpp
	@echo "编译 $@";
	$(CXX) -c $(CXXFLAGS) $< -o $@;

-include $(DEPS)
$(BUILD_PATH)/%.d : %.cpp 
	@echo "生成 $@";
	@if [ ! -d "$(dir $@)" ]; then \
		mkdir -pv $(dir $@); \
	fi
	@$(CXX) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;\
	rm -f $@.$$$$;

clean:
	@echo "删除"
	@rm -rf $(TARGET) $(BUILD_PATH)

show:
	@echo $(OBJS)
	@echo $(DEPS)

.PHONY : clean show
