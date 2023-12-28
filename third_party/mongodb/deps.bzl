# load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# _ALL_CONTENT = """\
# filegroup(
#     name = "all_srcs",
#     srcs = glob(["**/**/**"]),
#     visibility = ["//visibility:public"],
# )
# """

# def download_mongodb():
#     http_archive(
#         name = "mongoDB",
#         build_file_content = _ALL_CONTENT,
#         strip_prefix = "mongo-cxx-driver-r3.6.4",
#         sha256 = "4be223bb221c86fb07b41f92c19eebde2983f2e5ebcab90574b1a2075d0bf43a",
#         url = "https://github.com/mongodb/mongo-cxx-driver/releases/download/r3.6.4/mongo-cxx-driver-r3.6.4.tar.gz",
#     )
