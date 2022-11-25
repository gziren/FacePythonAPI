from __future__ import absolute_import
import os
import sys


def add_system_search_paths():
    # TODO(qiuyanjun): add Linux system paths
    sys_paths = os.environ["path"].strip().split(";")
    for sys_path in sys_paths:
        if os.path.exists(sys_path) and sys.version_info[:2] >= (3, 8):
            try:
                os.add_dll_directory(sys_path)
            except:
                continue


def add_dll_search_dir(dir_path):
    os.environ["path"] = dir_path + ";" + os.environ["path"]
    sys.path.insert(0, dir_path)
    if sys.version_info[:2] >= (3, 8):
        os.add_dll_directory(dir_path)


try:
    from .libs.PYFaceAPI import *
except:
    raise RuntimeError("FaceAPI initialized failed!")
