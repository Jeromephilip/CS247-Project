# List of subdirectories containing makefiles
SUBDIRS := dir1 dir2 dir3  # Add more subdirectories if needed

.PHONY: all clean

all:
    for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir; \
    done

clean:
    for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir clean; \
    done