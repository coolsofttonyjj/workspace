all:aoi testmap
	@echo "编译完成"

aoi:
	@gcc -o $@ -g -Wall aoi.c test.c

testmap:
	@gcc -o $@ -g -Wall testmap.c

clean:
	@rm -rf aoi testmap

.PHONY: clean
