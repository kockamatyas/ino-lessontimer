ARDUINO_LIBRARIES=()
GITHUB_LIBRARIES=("https://github.com/avishorp/TM1637.git")

export ARDUINO_LIBRARY_ENABLE_UNSAFE_INSTALL=true

for i in ${ARDUINO_LIBRARIES[@]}; do
	arduino-cli lib install --verbose $i
done
for i in ${GITHUB_LIBRARIES[@]}; do
	arduino-cli lib install --verbose --git-url $i
done;