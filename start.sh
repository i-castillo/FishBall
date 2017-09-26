#let Android find the JDK
export JAVA_HOME=/usr/java/jdk1.8.0_60

#let Android find the NDK
export ANDROID_NDK_ROOT=/home/georg/android-ndk-r10e

#set the path to the SDK
export PATH=$PATH:/home/georg/android-sdk-linux/tools

#set the path to the NDK
export PATH=$PATH:/home/georg/android-ndk-r10e

#set  a variable containing the standalone toolchain
export TC=/home/georg/android-toolchain

#set path to arm-linux-androideabi-gcc and friends
export PATH=$PATH:$TC/bin

#help the emulator find its ini files (optional)
export ANDROID_AVD_HOME=/home/georg/.android/avd
