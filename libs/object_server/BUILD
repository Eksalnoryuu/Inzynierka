load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "object_server",
    srcs = glob(["src/**/*.cpp"]),
    hdrs = glob([
        "src/**/*.h",
        "*.h",
        "src/**/*.inl",
        "*.inl",
    ]),
    copts = ["-Ilibs/utils/src"],
    visibility = ["//visibility:public"],
    deps = [
        "//third_party/spdlog",
        "//third_party/sqlite",
    ],
)