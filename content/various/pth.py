import os

# Snippet to add
snippet = """/**
 * Author: Null
 * Date: Happy new Year 2025
 * License: CC0
 * Source: Conversation with Håkan and Ulf.
 * Description: Example structures and functions that doesn't really do
 *  anything. Latex commands are supported here, though! Like this: $2^2=3$

 */\n\n"""

directory = "."

# Process all .h files in the current directory
for filename in os.listdir(directory):
    # Check if the file has a .h extension
    if filename.endswith(".h") and os.path.isfile(filename):
        # Rename the file by removing all underscores
        new_filename = filename.replace("_", "")
        os.rename(filename, new_filename)

        # Add the snippet to the renamed file
        with open(new_filename, "r+") as file:
            content = file.read()  # Read the existing content
            file.seek(0)  # Go back to the beginning of the file
            file.write(
                snippet + content
            )  # Write the snippet followed by the old content

print(
    "Snippet added and underscores removed from filenames for all .h files in the current directory."
)
