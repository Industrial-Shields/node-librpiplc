{
	"targets": [
		{
			"target_name": "rpiplc",
			"sources": [
				"src/analogRead.cpp",
				"src/analogWrite.cpp",
				"src/digitalRead.cpp",
				"src/digitalWrite.cpp",
				"src/initPins.cpp",
				"src/main.cpp",
				"src/pinMode.cpp",
				"src/version.cpp",
			],
			"include_dirs": [
				"/usr/local/include/rpiplc",
			],
			"libraries": [
				"-lrpiplc",
			],
		},
	],
}
