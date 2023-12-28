load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")


##############################
# G TEST
##############################

git_repository(
    name = "com_google_googletest",
    commit = "1b18723e874b256c1e39378c6774a90701d70f7a",
    remote = "https://github.com/google/googletest",
)

##############################
# FOREIGN CC
##############################

http_archive(
    name = "rules_foreign_cc",
    sha256 = "2a4d07cd64b0719b39a7c12218a3e507672b82a97b98c6a89d38565894cf7c51",
    strip_prefix = "rules_foreign_cc-0.9.0",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/0.9.0.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

##############################
# THIRD PARTY
##############################

new_local_repository(
    name = "system",
    build_file = "third_party/system/BUILD",
    path = "/usr",
)

load("//third_party:deps.bzl", "deps")

deps()

##############################
# CLANG
##############################

http_archive(
    name = "clang",
    strip_prefix = "bazel-compile-commands-extractor-5ceebcf367f51c6a18fffe726755951a43b50e45",
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/5ceebcf367f51c6a18fffe726755951a43b50e45.tar.gz",
)

load("@clang//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()


