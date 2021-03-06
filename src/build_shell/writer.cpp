/*
 * Copyright © 2013 Jørgen Lind

 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting documentation, and
 * that the name of the copyright holders not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no representations
 * about the suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.

 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
*/
#include "writer.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

Writer::Writer(std::string file)
    : m_file(0)
    , m_file_desc(-1)
{
    m_file_desc = ::open(file.c_str(), (O_WRONLY | O_CREAT | O_EXCL | O_CLOEXEC));
    if (m_file_desc >= 0) {
        m_file = fdopen(m_file_desc, "w");
        if (!m_file) {
            fprintf(stderr, "Failed to open filestream for file %s\n", file.c_str());
            exit(3);
        }
    } else {
        fprintf(stderr, "Failed to open file %s\n", file.c_str());
        exit(3);
    }
}

Writer::~Writer()
{
    if (m_file) {
        fclose(m_file);
        close(m_file_desc);
    }
}
