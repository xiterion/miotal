FROM debian:bookworm-slim@sha256:88200866dfff7ea7f5cbcb6ec7c8a701889efe6fe859fe64d6990e4b07ea4171

ARG ARM_GCC_VERSION=15.3.rel1
ARG ARM_GCC_URL=https://gitlab.arm.com/api/v4/projects/tooling%2Fgnu-toolchains-for-arm/packages/generic/gnu-toolchain/15.3.rel1/arm-gnu-toolchain-15.3.rel1-x86_64-arm-none-eabi.tar.xz
ARG ARM_GCC_SHA256=563bebb2b97d53382b956d6ee1fe61e2cae26699901417234a37df505ef9b5fa

RUN apt-get update && apt-get install -y --no-install-recommends curl ca-certificates xz-utils make cmake git \
    && rm -rf /var/lib/apt/lists/*

RUN curl -fsSL "$ARM_GCC_URL" -o /tmp/gcc.tar.xz \
    && echo "$ARM_GCC_SHA256  /tmp/gcc.tar.xz" | sha256sum -c - \
    && mkdir -p /opt/arm-gnu-toolchain \
    && tar -xf /tmp/gcc.tar.xz --strip-components=1 -C /opt/arm-gnu-toolchain \
    && rm /tmp/gcc.tar.xz

ENV PATH="/opt/arm-gnu-toolchain/bin:${PATH}"
WORKDIR /workspace
