FROM gcr.io/oss-fuzz-base/base-builder
RUN apt-get update && apt-get install -y autoconf automake libtool
RUN git clone --depth 1 https://github.com/rgamble/libcsv.git
WORKDIR libcsv
COPY build.sh $SRC/
COPY libcsv_fuzzer.cc $SRC/
