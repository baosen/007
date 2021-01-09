load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "io_bazel_rules_go",
    sha256 = "b725e6497741d7fc2d55fcc29a276627d10e43fa5d0bb692692890ae30d98d00",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_go/releases/download/v0.24.3/rules_go-v0.24.3.tar.gz",
        "https://github.com/bazelbuild/rules_go/releases/download/v0.24.3/rules_go-v0.24.3.tar.gz",
    ],
)

http_archive(
    name = "bazel_gazelle",
    sha256 = "b85f48fa105c4403326e9525ad2b2cc437babaa6e15a3fc0b1dbab0ab064bc7c",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-gazelle/releases/download/v0.22.2/bazel-gazelle-v0.22.2.tar.gz",
        "https://github.com/bazelbuild/bazel-gazelle/releases/download/v0.22.2/bazel-gazelle-v0.22.2.tar.gz",
    ],
)

load("@io_bazel_rules_go//go:deps.bzl", "go_register_toolchains", "go_rules_dependencies")
load("@bazel_gazelle//:deps.bzl", "gazelle_dependencies", "go_repository")

go_repository(
    name = "com_github_burntsushi_xgb",
    importpath = "github.com/BurntSushi/xgb",
    sum = "h1:1BDTz0u9nC3//pOCMdNH+CiXJVYJh5UQNCOBG7jbELc=",
    version = "v0.0.0-20160522181843-27f122750802",
)

go_repository(
    name = "com_github_creack_pty",
    importpath = "github.com/creack/pty",
    sum = "h1:uDmaGzcdjhF4i/plgjmEsriH11Y0o7RKapEf/LDaM3w=",
    version = "v1.1.9",
)

go_repository(
    name = "com_github_cznic_fileutil",
    importpath = "github.com/cznic/fileutil",
    sum = "h1:94XgeeTZ+3Xi9zsdgBjP1Byx/wywCImjF8FzQ7OaKdU=",
    version = "v0.0.0-20181122101858-4d67cfea8c87",
)

go_repository(
    name = "com_github_cznic_golex",
    importpath = "github.com/cznic/golex",
    sum = "h1:G8zTsaqyVfIHpgMFcGgdbhHSFhlNc77rAKkhVbQ9kQg=",
    version = "v0.0.0-20181122101858-9c343928389c",
)

go_repository(
    name = "com_github_cznic_goyacc",
    importpath = "github.com/cznic/goyacc",
    sum = "h1:HMTMwkFYFN6tGj95EdHHvz6Uy/1dyr3+g0obtkU0lbg=",
    version = "v0.0.0-20181122101858-930e7a3323cf",
)

go_repository(
    name = "com_github_cznic_lex",
    importpath = "github.com/cznic/lex",
    sum = "h1:KJtZdP0G3jUnpgEWZdJ7326WvTbREwcwlDSOpkpNZGY=",
    version = "v0.0.0-20181122101858-ce0fb5e9bb1b",
)

go_repository(
    name = "com_github_cznic_lexer",
    importpath = "github.com/cznic/lexer",
    sum = "h1:K5kIaw68kxYw40mp8YKuwKrb63R0BPCR1iEGvBR6Mfs=",
    version = "v0.0.0-20181122101858-e884d4bd112e",
)

go_repository(
    name = "com_github_cznic_mathutil",
    importpath = "github.com/cznic/mathutil",
    sum = "h1:iwZdTE0PVqJCos1vaoKsclOGD3ADKpshg3SRtYBbwso=",
    version = "v0.0.0-20181122101859-297441e03548",
)

go_repository(
    name = "com_github_cznic_parser",
    importpath = "github.com/cznic/parser",
    sum = "h1:DUtr2TvhM9rmiHKVJWoLqDY2+MdxljW9hlaS/oYoi1c=",
    version = "v0.0.0-20181122101858-d773202d5b1f",
)

go_repository(
    name = "com_github_cznic_sortutil",
    importpath = "github.com/cznic/sortutil",
    sum = "h1:LpMLYGyy67BoAFGda1NeOBQwqlv7nUXpm+rIVHGxZZ4=",
    version = "v0.0.0-20181122101858-f5f958428db8",
)

go_repository(
    name = "com_github_cznic_strutil",
    importpath = "github.com/cznic/strutil",
    sum = "h1:MZRmHqDBd0vxNwenEbKSQqRVT24d3C05ft8kduSwlqM=",
    version = "v0.0.0-20181122101858-275e90344537",
)

go_repository(
    name = "com_github_cznic_y",
    importpath = "github.com/cznic/y",
    sum = "h1:gvFsf4zJcnW6GRN+HPGTxwuw+7sTwzmoeoBQQCZDEnk=",
    version = "v0.0.0-20181122101901-b05e8c2e8d7b",
)

go_repository(
    name = "com_github_go_gl_glfw_v3_3_glfw",
    importpath = "github.com/go-gl/glfw/v3.3/glfw",
    sum = "h1:WtGNWLvXpe6ZudgnXrq0barxBImvnnJoMEhXAzcbM0I=",
    version = "v0.0.0-20200222043503-6f7a984d4dc4",
)

go_repository(
    name = "com_github_google_go_cmp",
    importpath = "github.com/google/go-cmp",
    sum = "h1:Xye71clBPdm5HgqGwUkwhbynsUJZhDbS20FvLhQ2izg=",
    version = "v0.3.1",
)

go_repository(
    name = "com_github_kr_pretty",
    importpath = "github.com/kr/pretty",
    sum = "h1:Fmg33tUaq4/8ym9TJN1x7sLJnHVwhP33CNkpYV/7rwI=",
    version = "v0.2.1",
)

go_repository(
    name = "com_github_kr_pty",
    importpath = "github.com/kr/pty",
    sum = "h1:VkoXIwSboBpnk99O/KFauAEILuNHv5DVFKZMBN/gUgw=",
    version = "v1.1.1",
)

go_repository(
    name = "com_github_kr_text",
    importpath = "github.com/kr/text",
    sum = "h1:5Nx0Ya0ZqY2ygV366QzturHI13Jq95ApcVaJBhpS+AY=",
    version = "v0.2.0",
)

go_repository(
    name = "com_github_llir_ll",
    importpath = "github.com/llir/ll",
    sum = "h1:z6EvJzdc2EbZK4yN+1QmvX1ecMni/1yCmG//dqrJT3E=",
    version = "v0.0.0-20201222174523-a5dcfe236594",
)

go_repository(
    name = "com_github_llir_llvm",
    importpath = "github.com/llir/llvm",
    sum = "h1:6CgtInA28DTfUtbzLkQkCbg/8GJRkxuegmWYU9o91FE=",
    version = "v0.3.3-0.20201226104203-9ddfbacf138e",
)

go_repository(
    name = "com_github_mewmew_float",
    importpath = "github.com/mewmew/float",
    sum = "h1:R27wrYHe8Zik4z/EV8xxfoH3cwMJw3qI4xsI3yYkGDQ=",
    version = "v0.0.0-20201204173432-505706aa38fa",
)

go_repository(
    name = "com_github_pkg_errors",
    importpath = "github.com/pkg/errors",
    sum = "h1:FEBLx1zS214owpjy7qsBeixbURkuhQAwrK5UwLGTwt4=",
    version = "v0.9.1",
)

go_repository(
    name = "com_github_remyoudompheng_bigfft",
    importpath = "github.com/remyoudompheng/bigfft",
    sum = "h1:OdAsTTz6OkFY5QxjkYwrChwuRruF69c169dPK26NUlk=",
    version = "v0.0.0-20200410134404-eec4a21b6bb0",
)

go_repository(
    name = "com_github_yuin_goldmark",
    importpath = "github.com/yuin/goldmark",
    sum = "h1:ruQGxdhGHe7FWOJPT0mKs5+pD2Xs1Bm/kdGlHO04FmM=",
    version = "v1.2.1",
)

go_repository(
    name = "com_shuralyov_dmitri_gpu_mtl",
    importpath = "dmitri.shuralyov.com/gpu/mtl",
    sum = "h1:+PdD6GLKejR9DizMAKT5DpSAkKswvZrurk1/eEt9+pw=",
    version = "v0.0.0-20201218220906-28db891af037",
)

go_repository(
    name = "org_golang_x_crypto",
    importpath = "golang.org/x/crypto",
    sum = "h1:psW17arqaxU48Z5kZ0CQnkZWQJsqcURM6tKiBApRjXI=",
    version = "v0.0.0-20200622213623-75b288015ac9",
)

go_repository(
    name = "org_golang_x_exp",
    importpath = "golang.org/x/exp",
    sum = "h1:GnGfrp0fiNhiBS/v/aCFTmfEWgkvxW4Qiu8oM2/IfZ4=",
    version = "v0.0.0-20201221025956-e89b829e73ea",
)

go_repository(
    name = "org_golang_x_image",
    importpath = "golang.org/x/image",
    sum = "h1:+qEpEAPhDZ1o0x3tHzZTQDArnOixOzGD9HUJfcg0mb4=",
    version = "v0.0.0-20190802002840-cff245a6509b",
)

go_repository(
    name = "org_golang_x_mobile",
    importpath = "golang.org/x/mobile",
    sum = "h1:kgfVkAEEQXXQ0qc6dH7n6y37NAYmTFmz0YRwrRjgxKw=",
    version = "v0.0.0-20201217150744-e6ae53a27f4f",
)

go_repository(
    name = "org_golang_x_mod",
    importpath = "golang.org/x/mod",
    sum = "h1:8pl+sMODzuvGJkmj2W4kZihvVb5mKm8pB/X44PIQHv8=",
    version = "v0.4.0",
)

go_repository(
    name = "org_golang_x_net",
    importpath = "golang.org/x/net",
    sum = "h1:IX6qOQeG5uLjB/hjjwjedwfjND0hgjPMMyO1RoIXQNI=",
    version = "v0.0.0-20201021035429-f5854403a974",
)

go_repository(
    name = "org_golang_x_sync",
    importpath = "golang.org/x/sync",
    sum = "h1:SQFwaSi55rU7vdNs9Yr0Z324VNlrF+0wMqRXT4St8ck=",
    version = "v0.0.0-20201020160332-67f06af15bc9",
)

go_repository(
    name = "org_golang_x_sys",
    importpath = "golang.org/x/sys",
    sum = "h1:+Nyd8tzPX9R7BWHguqsrbFdRx3WQ/1ib8I44HXV5yTA=",
    version = "v0.0.0-20200930185726-fdedc70b468f",
)

go_repository(
    name = "org_golang_x_text",
    importpath = "golang.org/x/text",
    sum = "h1:cokOdA+Jmi5PJGXLlLllQSgYigAEfHXJAERHVMaCc2k=",
    version = "v0.3.3",
)

go_repository(
    name = "org_golang_x_tools",
    importpath = "golang.org/x/tools",
    sum = "h1:f73n5dlgZQAo1xrt5zWiCfBVp5cU8O9UZVaGRhuDUw8=",
    version = "v0.0.0-20201228185149-0661ca7ea1ee",
)

go_repository(
    name = "org_golang_x_xerrors",
    importpath = "golang.org/x/xerrors",
    sum = "h1:go1bK/D/BFZV2I8cIQd1NKEZ+0owSTG1fDTci4IqFcE=",
    version = "v0.0.0-20200804184101-5ec99f83aff1",
)

go_rules_dependencies()

go_register_toolchains()

gazelle_dependencies()
