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
				"/usr/include/librpiplc/include",
				"/usr/include/librpiplc/include/include",
				"/usr/local/include/librpiplc/include",
				"/usr/local/include/librpiplc/include/include",
			],
			"libraries": [
				"-lrpiplc",
			],
		},
	],
	"actions_before_build": [
    			{
      				"action_name": "Clone and build rpiplc-lib library",
      				"inputs": [],
      				"outputs": [],
      				"action": [
        				{
          					"action_name": "Clone rpiplc-lib repository",
          					"inputs": [],
          					"outputs": [],
          					"action": ["git", "clone", "https://github.com/Industrial-Shields/rpiplc-lib.git"]
        				},
        				{
         					"action_name": "Build rpiplc-lib library",
          					"inputs": [],
          					"outputs": [],
          					"action": [
            						{
								"action_name": "Change_directory", "action": ["cd", "rpiplc-lib"]
							},
            						{
								"action_name": "Make", "action": ["make"]
							},
           	 					{
								"action_name": "Install", "action": ["sudo", "make", "install"]
							},
            						{
								"action_name": "Go_back_directory", "action": ["cd", ".."]
							}
          				]
        		},
      	],
}
