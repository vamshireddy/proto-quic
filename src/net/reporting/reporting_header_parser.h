// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_REPORTING_REPORTING_HEADER_PARSER_H_
#define NET_REPORTING_REPORTING_HEADER_PARSER_H_

#include <string>

#include "base/macros.h"
#include "base/time/time.h"
#include "net/base/net_export.h"

class GURL;

namespace base {
class Value;
}  // namespace base

namespace net {

class ReportingCache;

// Parses Report-To headers and writes the endpoint configurations to the
// ReportingCache.
class NET_EXPORT ReportingHeaderParser {
 public:
  // Parses the normalized Report-To header value |json_value| sent in response
  // to a request for |url| at |now|, and applies the endpoint configurations
  // to |cache|.
  static void ParseHeader(ReportingCache* cache,
                          base::TimeTicks now,
                          const GURL& url,
                          const std::string& json_value);

 private:
  // Processes a single endpoint's parsed value from the Report-To header(s).
  // Creates, updates, or removes a client in the cache as needed.
  //
  // |url| is the URL that the header came from.
  //
  // |value| is the parsed value.
  static void ProcessEndpoint(ReportingCache* cache,
                              base::TimeTicks now,
                              const GURL& url,
                              const base::Value& value);

  DISALLOW_IMPLICIT_CONSTRUCTORS(ReportingHeaderParser);
};

}  // namespace net

#endif  // NET_REPORTING_REPORTING_HEADER_PARSER_H_
