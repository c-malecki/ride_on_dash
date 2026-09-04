package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"path/filepath"
	"strings"
	"text/template"
)

type TemplateData struct {
	Name      string // e.g., "home"
	UpperName string // e.g., "HOME"
	TitleName string // e.g., "Home"
}

const headerTemplate = `// {{.Name}}.h
#ifndef __{{.UpperName}}_H_
#define __{{.UpperName}}_H_

#include "definitions.h"

extern const UI_Screen_t UI_Screen_{{.TitleName}};

#endif // __{{.UpperName}}_H_
`

const sourceTemplate = `// {{.Name}}.c
#include "{{.Name}}.h"
#include "_color.h"
#include "button_base.h"
#include "style.h"
#include "ui_engine.h"

/* Local State */

/* UI Actions */

/* UI Configs */

/* Render Function */

static void render(lv_obj_t *container) {

}

/* Export */

const UI_Screen_t UI_Screen_{{.TitleName}} = {
    .screen_id = UI_SCREEN_ID_{{.UpperName}},
    .render_fn = render,
};
`

func main() {
	dirFlag := flag.String("dir", "", "Target base directory path (e.g., ./my/path)")
	nameFlag := flag.String("name", "", "Name of the component (e.g., home)")
	typeFlag := flag.String("type", "screen", "Template type to generate")
	flag.Parse()

	if *dirFlag == "" || *nameFlag == "" {
		log.Fatal("Error: Both -dir and -name flags are required. Example: -dir=./my/path -name=home")
	}

	if *typeFlag != "screen" {
		log.Fatalf("Error: Unsupported type '%s'. Currently supported: screen", *typeFlag)
	}

	cleanDir := filepath.Clean(*dirFlag)
	rawName := strings.TrimSpace(*nameFlag)

	// Capitalize first letter while preserving case for TitleName (e.g., "home" -> "Home")
	titleName := strings.ToUpper(rawName[:1]) + rawName[1:]

	// Prepare dynamic values for templates
	data := TemplateData{
		Name:      strings.ToLower(rawName),
		UpperName: strings.ToUpper(rawName),
		TitleName: titleName,
	}

	// Ensure base directory exists
	if err := os.MkdirAll(cleanDir, 0755); err != nil {
		log.Fatalf("Failed to create directory %s: %v", cleanDir, err)
	}

	// File definitions directly in target directory
	files := map[string]string{
		filepath.Join(cleanDir, data.Name+".h"): headerTemplate,
		filepath.Join(cleanDir, data.Name+".c"): sourceTemplate,
	}

	// Write files
	for filePath, tmplStr := range files {
		if err := createFileFromTemplate(filePath, tmplStr, data); err != nil {
			log.Fatalf("Error generating file %s: %v", filePath, err)
		}
		fmt.Printf("Generated: %s\n", filePath)
	}
}

func createFileFromTemplate(filePath string, tmplContent string, data TemplateData) error {
	f, err := os.Create(filePath)
	if err != nil {
		return err
	}
	defer f.Close()

	tmpl, err := template.New("cfile").Parse(tmplContent)
	if err != nil {
		return err
	}

	return tmpl.Execute(f, data)
}
