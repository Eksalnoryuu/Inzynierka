
load("//third_party/spdlog:deps.bzl", "download_spdlog")
load("//third_party/boost:deps.bzl", "download_boost")
#load("//third_party/mongodb:deps.bzl", "download_mongodb")
load("//third_party/sqlite:deps.bzl", "download_sqlite")

def deps():
    "Load_all_third_party_rules"
    download_spdlog()
    download_boost()
    #download_mongodb()
    download_sqlite()
