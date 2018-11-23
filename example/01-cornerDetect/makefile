CXXFLAGS=g++

LIBS=-lopencv_core \
	 -lopencv_highgui \
	 -lopencv_imgproc \
	 -lopencv_imgcodecs

TARGETS = cornerDetect.out

build: $(TARGETS)
cornerDetect.out: cornerDetect.cpp
	$(CXXFLAGS) $^ -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -fr $(TARGETS)