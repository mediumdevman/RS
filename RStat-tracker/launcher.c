#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <mach-o/dyld.h>  // macOS-specific header for getting the executable path

int main() {
    char exe_path[PATH_MAX];  // Buffer to store executable path
    uint32_t size = sizeof(exe_path);

    // Get the absolute path of the executable on macOS
    if (_NSGetExecutablePath(exe_path, &size) != 0) {
        perror("Error getting executable path");
        return 1;
    }

    // Find the last slash ('/') to get the directory
    char *last_slash = strrchr(exe_path, '/');
    if (last_slash != NULL) {
        *last_slash = '\0';  // Remove the executable name to get the directory
    }

    // Change to the directory of the executable
    if (chdir(exe_path) != 0) {
        perror("Failed to change directory");
        return 1;
    }

    // Ensure run.sh is executable
    system("chmod +x run.sh");

    // Run run.sh from the correct directory
    int result = system("./run.sh");

    if (result == -1) {
        printf("Error: Unable to launch RStat-Tracker\n");
        return 1;
    }

    return 0;
}
