{
	"targets": [
		{
			"target_name": "rpiplc",
			"sources": [
				"src/analogRead.cpp",
				"src/analogWrite.cpp",
				"src/analogWriteSetFrequency.cpp",
				"src/delay.cpp",
				"src/digitalRead.cpp",
				"src/digitalWrite.cpp",
				"src/initExpandedGPIO.cpp",
				"src/main.cpp",
				"src/pinMode.cpp",
				"src/version.cpp",
			],
			"defines": [ "DONT_IMPORT_MAPPING" ],
			"include_dirs": [
				"/usr/local/include/librpiplc/include",
				"/usr/local/include/librpiplc/include/include",
			],
			"libraries": [
				"-lrpiplc",
			],
		},
	],
}
