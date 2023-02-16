; Auto-generated. Do not edit!


(cl:in-package air_lab4-srv)


;//! \htmlinclude ExecuteTst-request.msg.html

(cl:defclass <ExecuteTst-request> (roslisp-msg-protocol:ros-message)
  ((tst_file
    :reader tst_file
    :initarg :tst_file
    :type cl:string
    :initform ""))
)

(cl:defclass ExecuteTst-request (<ExecuteTst-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ExecuteTst-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ExecuteTst-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name air_lab4-srv:<ExecuteTst-request> is deprecated: use air_lab4-srv:ExecuteTst-request instead.")))

(cl:ensure-generic-function 'tst_file-val :lambda-list '(m))
(cl:defmethod tst_file-val ((m <ExecuteTst-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader air_lab4-srv:tst_file-val is deprecated.  Use air_lab4-srv:tst_file instead.")
  (tst_file m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ExecuteTst-request>) ostream)
  "Serializes a message object of type '<ExecuteTst-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'tst_file))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'tst_file))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ExecuteTst-request>) istream)
  "Deserializes a message object of type '<ExecuteTst-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'tst_file) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'tst_file) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ExecuteTst-request>)))
  "Returns string type for a service object of type '<ExecuteTst-request>"
  "air_lab4/ExecuteTstRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ExecuteTst-request)))
  "Returns string type for a service object of type 'ExecuteTst-request"
  "air_lab4/ExecuteTstRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ExecuteTst-request>)))
  "Returns md5sum for a message object of type '<ExecuteTst-request>"
  "44f7b4ced43e85a05e62b2b38ffc3b46")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ExecuteTst-request)))
  "Returns md5sum for a message object of type 'ExecuteTst-request"
  "44f7b4ced43e85a05e62b2b38ffc3b46")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ExecuteTst-request>)))
  "Returns full string definition for message of type '<ExecuteTst-request>"
  (cl:format cl:nil "string tst_file         # Name of the TST file to execute~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ExecuteTst-request)))
  "Returns full string definition for message of type 'ExecuteTst-request"
  (cl:format cl:nil "string tst_file         # Name of the TST file to execute~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ExecuteTst-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'tst_file))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ExecuteTst-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ExecuteTst-request
    (cl:cons ':tst_file (tst_file msg))
))
;//! \htmlinclude ExecuteTst-response.msg.html

(cl:defclass <ExecuteTst-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil)
   (error_message
    :reader error_message
    :initarg :error_message
    :type cl:string
    :initform ""))
)

(cl:defclass ExecuteTst-response (<ExecuteTst-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ExecuteTst-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ExecuteTst-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name air_lab4-srv:<ExecuteTst-response> is deprecated: use air_lab4-srv:ExecuteTst-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <ExecuteTst-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader air_lab4-srv:success-val is deprecated.  Use air_lab4-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'error_message-val :lambda-list '(m))
(cl:defmethod error_message-val ((m <ExecuteTst-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader air_lab4-srv:error_message-val is deprecated.  Use air_lab4-srv:error_message instead.")
  (error_message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ExecuteTst-response>) ostream)
  "Serializes a message object of type '<ExecuteTst-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'error_message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'error_message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ExecuteTst-response>) istream)
  "Deserializes a message object of type '<ExecuteTst-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'error_message) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'error_message) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ExecuteTst-response>)))
  "Returns string type for a service object of type '<ExecuteTst-response>"
  "air_lab4/ExecuteTstResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ExecuteTst-response)))
  "Returns string type for a service object of type 'ExecuteTst-response"
  "air_lab4/ExecuteTstResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ExecuteTst-response>)))
  "Returns md5sum for a message object of type '<ExecuteTst-response>"
  "44f7b4ced43e85a05e62b2b38ffc3b46")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ExecuteTst-response)))
  "Returns md5sum for a message object of type 'ExecuteTst-response"
  "44f7b4ced43e85a05e62b2b38ffc3b46")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ExecuteTst-response>)))
  "Returns full string definition for message of type '<ExecuteTst-response>"
  (cl:format cl:nil "bool success            # Whether the execution was succesful~%string error_message    # Error message if the execution was unsuccessful~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ExecuteTst-response)))
  "Returns full string definition for message of type 'ExecuteTst-response"
  (cl:format cl:nil "bool success            # Whether the execution was succesful~%string error_message    # Error message if the execution was unsuccessful~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ExecuteTst-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'error_message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ExecuteTst-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ExecuteTst-response
    (cl:cons ':success (success msg))
    (cl:cons ':error_message (error_message msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ExecuteTst)))
  'ExecuteTst-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ExecuteTst)))
  'ExecuteTst-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ExecuteTst)))
  "Returns string type for a service object of type '<ExecuteTst>"
  "air_lab4/ExecuteTst")