def inflate(**kwargs):
    native.genrule(
        cmd = "./$(location //tools/rz/inflate) $(location //roms:usa.z64) $(location :data.json) $(@D)",
        tools = ["//tools/rz/inflate"],
        **kwargs
    )
