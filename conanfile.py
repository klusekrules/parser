from conans import ConanFile, CMake


class ParserConan(ConanFile):
    name = "parser"
    version = "0.5"
    license = "MIT"
    url = "https://github.com/klusekrules/parser"
    description = "Parser plików"
    settings = "os", "compiler", "build_type", "arch"
    requires = "types/0.5@klusek_rules/stable", "jsoncpp/1.8.4@theirix/stable", "tinyxml2/3.0.0@klusek_rules/stable"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    generators = "cmake"
    exports_sources = "src/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        cmake.build()

        # Explicit way:
        # self.run('cmake %s/hello %s'
        #          % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.h", dst="include/Parser", src="src")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["parser"]
