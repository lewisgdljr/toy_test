#!/bin/bash

file_pattern="${1:-*.hpp}"
file_location_raw="${2:-include}"
file_location="${file_location_raw#./}"

extract_doc()
{
    local curr_file;
    curr_file="${1#${file_location}/}"
    echo "" >> "doc/Documentation.md"
    echo "## ${curr_file}" >> "doc/Documentation.md"
    echo "" >> "doc/Documentation.md"
    grep '//>' "${1}" | sed -e 's%.*//>[[:space:]]*%%g' -e 's/^#/###/' >> "doc/Documentation.md"
}

for i in $(find "${file_location}" -name "${file_pattern}"); do
    extract_doc $i;
done

