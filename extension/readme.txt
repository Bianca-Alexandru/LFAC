steps to get the extension working

1. ctrl + shift + p  -> open user settings
2. copy these anywhere inside

"editor.tokenColorCustomizations": {
        "textMateRules": [
            {
                "name": "Hot Pink World Delimiters",
                "scope": "keyword.control.world.lfac",
                "settings": { 
                    "foreground": "#f8508b", 
                    "fontStyle": "bold" 
                }
            },
            {
                "scope": "keyword.control.main.lfac",
                "settings": { 
                    "foreground": "#ffcbe5", 
                }
            },
            {
                "name": "rest",
                "scope": "variable.other.rest.lfac",
                "settings": { 
                    "foreground": "#b6f2fb"
                }
            },
            {
                "name": "while, if, void, functions",
                "scope": "keyword.control.lfac",
                "settings": { "foreground": "#f853c9" }
            },
            {
                "name": "strings",
                "scope": "string.quoted.custom.lfac",
                "settings": { "foreground": "#7dcef9" ,
                            "fontStyle": "italic"}
            },
            {
                "name": "operations ",
                "scope": "keyword.operator.yellow.lfac",
                "settings": { "foreground": "#b899f5" }
            },
            {
                "name": "com and Complex Numbers",
                "scope": "constant.character.complex.lfac",
                "settings": { "foreground": "#e18cf8" }
            },
            {
                "name": "bool and T/F ",
                "scope": "constant.language.boolean.lfac",
                "settings": { "foreground": "#9971f6" }
            },
            {
                "name": " int, float, and numbers",
                "scope": "constant.numeric.standard.lfac",
                "settings": { "foreground": "#83c8f7" }
            }
        ]
    },

3. delete the readme.txt (optional)
4. make sure you have the folder with the extension folder opened
5. run 
cp -r ./extension ~/.vscode/extensions/lfac-extension
6. restart vscode
7. if it doesnt work look in the bottom right corner and set the language to LFAC instead of plain text