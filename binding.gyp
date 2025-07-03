{
	"targets": [
		{
			"target_name": "rpiplc",
			"sources": [
				"src/analogRead.cpp",
				"src/analogWrite.cpp",
				"src/analogWriteSetFrequency.cpp",
				"src/_cPopulateArrays.cpp",
				"src/deinitExpandedGPIO.cpp",
				"src/deinitExpandedGPIONoReset.cpp",
				"src/delay.cpp",
				"src/digitalRead.cpp",
				"src/digitalWrite.cpp",
				"src/functions.cpp",
				"src/initExpandedGPIO.cpp",
				"src/main.cpp",
				"src/pinMode.cpp",
			],
			"cflags": [ "-Wall -Wextra -Werror -fanalyzer" ]
		},
	],
}
