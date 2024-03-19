{
	"targets": [
		{
			"target_name": "rpiplc",
			"sources": [
				"src/analogRead.cpp",
				"src/analogWrite.cpp",
				"src/delay.cpp",
				"src/digitalRead.cpp",
				"src/digitalWrite.cpp",
				"src/initExpandedGPIO.cpp",
				"src/main.cpp",
				"src/pinMode.cpp",
			],
			"defines": [ "DONT_IMPORT_MAPPING" ],
			"include_dirs": [
				"/usr/local/include/librpiplc/include",
			],
			"libraries": [
				"-lrpiplc",
			],
		},
	],
}
