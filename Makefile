DIR:= algorithm aoi class socket test

clean:
	@for i in $(DIR); do \
		set -e; cd $$i; make clean; cd ..;\
	done;

.PHONY : clean
